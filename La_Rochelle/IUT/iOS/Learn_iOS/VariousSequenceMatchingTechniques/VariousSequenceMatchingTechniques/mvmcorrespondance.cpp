/*!
  \author Abdourahman Aden Hassan
  \date 01/01/2014
 */

#include "mvmcorrespondance.h"
#include "typeinfo"
#include "Exc.h"
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <cstdlib>
#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

using namespace std;
using namespace calc;


vector<calc::ResultatCorrespondance> *calc::MvmCorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{

    // Initialisation
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();
    ResultatCorrespondance rc;
    rc.correspondanceT1 = new vector<int>();
    rc.correspondanceT2 = new vector<int>();
    // Parametrage
    if(s1->getSize() != pCparam->getS2Size())
    {
        pCparam->setS2Size(s1->getSize());
    }
    if(s2->getSize() != pCparam->getS1Size())
    {
        pCparam->setS1Size(s2->getSize());
    }
    // Check entrées
    if(s1->getSize()<=0 || s2->getSize()<=0)
    {
        delete rc.correspondanceT1;
        delete rc.correspondanceT2;
        delete vRc;
        exc::SequenceMatchingException::genererException("Size error 2",PARAMETRE_INVALIDE,__LINE__);
    }
    if( s1->getSize()<s2->getSize())
    {

        delete rc.correspondanceT1;
        delete rc.correspondanceT2;
        delete vRc;
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    if(typeid(*s1->getElement(0))!=typeid(*s2->getElement(0)))
    {
        delete rc.correspondanceT1;
        delete rc.correspondanceT2;
        delete vRc;
        exc::SequenceMatchingException::genererException("Type error",PARAMETRE_INVALIDE,__LINE__);
    }
    if(typeid(*s1->getElement(0))==typeid(model::CharacteristicVector))
    {
        model::CharacteristicVector * cv1 = (model::CharacteristicVector *)s1->getElement(0);
        model::CharacteristicVector * cv2 = (model::CharacteristicVector *)s2->getElement(0);
        if(cv1->getSize() != cv2->getSize())
        {
            delete rc.correspondanceT1;
            delete rc.correspondanceT2;
            delete vRc;
            exc::SequenceMatchingException::genererException("Characteristic vector size error",PARAMETRE_INVALIDE,__LINE__);
        }

        if(cv1->getSize()!=pCparam->getVecCaracSize())
        {
            pCparam->setVecCaracSize(cv1->getSize());
        }
    }
    model::Sequence *cs1 = s1->copy();
    model::Sequence *cs2 = s2->copy();
    parametrerVectors(cs2, cs1);
    // Algorithme
    // Initialisation tableaux
    float ** tabDiff = initTabDifference(cs2,cs1);
	float ** pathCost = new float*[cs2->getSize()];
    int ** path = new int*[cs2->getSize()];
    int * s2index = new int[cs2->getSize()];;

    int itM = 0;
    while(itM<cs2->getSize())
    {
		pathCost[itM] = new float[cs1->getSize()];
		path[itM] = new int[cs1->getSize()];
        itM = itM +1;
    }
    //Calcul
    int tmp1 = cs1->getSize()- cs2->getSize();
    int tmp2 = 1 + round(cs2->getSize()/(float)(pCparam->getMvMDivElastic()));
    int elasticity = std::max(tmp1, tmp2);

    int i = 1;
    int j = 1;
    while(i<=cs2->getSize())
    {
        while(j<=cs1->getSize())
        {
            pathCost[i-1][j-1] = FLT_MAX ;
            path[i-1][j-1] = 0 ;
            j = j +1;
        }
        j = 1;
        i = i+1;
    }
    j = 1;
    while(j<=elasticity+1)
    {
        pathCost[1-1][j-1] = calcTab(tabDiff,1-1,j-1);
        j = j +1;
    }

    i = 2;
    j = 1;
    while(i<=cs2->getSize())
    {
        int stopk = min(i-1+elasticity,cs1->getSize());
        int debk=max(1,i-1);
        int k = debk;
        while(k <= stopk)
        {
            int stopj = min(k+1+elasticity,cs1->getSize());
            j = k+1;
            while(j<=stopj)
            {
                if(pathCost[i-1][j-1]>pathCost[i-1-1][k-1]+calcTab(tabDiff,i-1,j-1))
                {
                    pathCost[i-1][j-1] = pathCost[i-1-1][k-1]+calcTab(tabDiff,i-1,j-1);
                    path[i-1][j-1] = k;
                }
                j = j +1;
            }
            k = k + 1;
        }
        i = i + 1;
    }

    s2index[cs2->getSize() - 1] = 0;
    i = 1;
    while(i<cs1->getSize())
    {
        if(pathCost[cs2->getSize() - 1][i] <= pathCost[cs2->getSize() - 1][s2index[cs2->getSize() - 1]])
        {
            s2index[cs2->getSize() - 1] = i;
        }
        i = i + 1;
    }
    i = 1;
    while(i<cs2->getSize())
    {
        s2index[cs2->getSize()-i-1] = path[cs2->getSize()-i][s2index[cs2->getSize()-i]]-1;
        i = i +1;
    }
    i = 1;
    while(i<=cs2->getSize())
    {
        rc.correspondanceT1->push_back(s2index[i-1]);
        rc.correspondanceT2->push_back(i-1);
        i = i +1;
    }
    rc.distance = sqrt(pathCost[cs2->getSize()-1][cs1->getSize()-1]);
    // Libération tableaux
    freeTabDifference(tabDiff,cs2->getSize(),cs1->getSize());
    itM = 0;
    while(itM<cs2->getSize())
    {
        delete pathCost[itM];
        delete path[itM];
        itM = itM + 1;
    }
    delete path;
    delete pathCost;
    delete s2index;
    delete cs1;
    delete cs2;
	vRc->push_back(rc);
    return vRc;
}
