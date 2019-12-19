/*!
  \author Bastien Meunier
  \date 01/01/2014
 */

#include "cdpcorrespondance.h"
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

float CDPCorrespondance::min3(float f1, float f2, float f3)
{
	float min = f1;
	if(f2 < min)
		min = f2;
	if(f3 < min)
		min = f3;
	return min;
}

vector<calc::ResultatCorrespondance> *calc::CDPCorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{
	//s1 : target
	//s2 : ref
	 // Initialisation
	s1->toString();
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();
   	vector<int> *imin;
	if( s1->getSize()<s2->getSize())
    {
		model::Sequence *stamp = s2;
		s2 = s1;
		s1 = stamp;
    }
    // Parametrage
    if(s1->getSize() != pCparam->getS1Size())
    {
        pCparam->setS1Size(s1->getSize());
    }
    if(s2->getSize() != pCparam->getS2Size())
    {
        pCparam->setS2Size(s2->getSize());
    }
    // Check entrées
    if(s1->getSize()<=0 || s2->getSize()<=0)
    {
		delete vRc;
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    if(typeid(*s1->getElement(0))!=typeid(*s2->getElement(0)))
    {
        delete vRc;
        exc::SequenceMatchingException::genererException("Type error",PARAMETRE_INVALIDE,__LINE__);
    }
	if(typeid(*s1->getElement(0))==typeid(model::CharacteristicVector))
    {
        model::CharacteristicVector * cv1 = (model::CharacteristicVector *)s1->getElement(0);
        model::CharacteristicVector * cv2 = (model::CharacteristicVector *)s2->getElement(0);
        if(cv1->getSize() != cv2->getSize())
        {
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
    parametrerVectors(cs1, cs2);
	//Algorithme
	float ** tabDiff = initTabDifference(cs1,cs2);
	float ** pathCost = new float*[cs1->getSize()+2];

	int itT = 0;
	int itM = 0;
	while(itT<(cs1->getSize()+2))
    {
		pathCost[itT] = new float[cs2->getSize()];
		itT = itT + 1;
	}
	int j = 0;
/*	std::cout << "\t";
	while(j<cs2->getSize())
	{
		model::CharacteristicVector * tamp2 = (model::CharacteristicVector *)(cs2->getElement(j));
		std::cout <<tamp2->toString() <<  "\t";
		//pathCost[1][j] = FLT_MAX ;
		j++;
	}
	std::cout << endl;
	std::cout << "\t";*/
	j = 0;
	while(j<cs2->getSize())
	{
		pathCost[0][j] = FLT_MAX ;
//		std::cout << "inf" << "\t";
		pathCost[1][j] = FLT_MAX ;
		j++;
	}
/*	std::cout << endl;
	std::cout << "\t";
	j = 0;
	while(j<cs2->getSize())
	{
		std::cout << "inf" << "\t";
		j++;
	}
	std::cout << endl;*/
	int i = 0;
	int k = 2;
	j = 0;
	while(i<cs1->getSize()){
		j = 0;
//	model::CharacteristicVector * tamp2 = (model::CharacteristicVector *)(cs1->getElement(i));
//		std::cout <<tamp2->toString() <<  "\t";
		while(j<cs2->getSize())
		{
			if(j == 0)
				pathCost[k][j] = 3*calcTab(tabDiff,i,j);
			else if(j == 1){
				if(k == 2)
					pathCost[k][j] = min3(FLT_MAX,pathCost[k-1][j-1] + 3*calcTab(tabDiff,i,j),pathCost[k][j-1] + 3*calcTab(tabDiff,i,j));
				else
					pathCost[k][j] = min3(pathCost[k-2][j-1] + 2*calcTab(tabDiff,i-1,j) + calcTab(tabDiff,i,j), pathCost[k-1][j-1] + 3*calcTab(tabDiff,i,j),pathCost[k][j-1] + 3*calcTab(tabDiff,i,j));
			}
			else{
				if(k == 2)
					pathCost[k][j] = min3(FLT_MAX,pathCost[k-1][j-1] + 3*calcTab(tabDiff,i,j),pathCost[k-1][j-2] + 3*calcTab(tabDiff,i,j-1) + 3*calcTab(tabDiff,i,j));
				else
					pathCost[k][j] =min3(pathCost[k-2][j-1] + 2*calcTab(tabDiff,i-1,j) + calcTab(tabDiff,i,j), pathCost[k-1][j-1] + 3*calcTab(tabDiff,i,j),pathCost[k-1][j-2] + 3*calcTab(tabDiff,i,j-1) + 3*calcTab(tabDiff,i,j));
			}
//			(pathCost[k][j] == FLT_MAX) ? cout << "inf" << "\t" : cout << pathCost[k][j] << "\t";
			j = j + 1;
		}
//		std::cout << endl;
		i = i + 1;
		k = k + 1;
	}
//	std::cout << endl;
	freeTabDifference(tabDiff,cs1->getSize(),cs2->getSize());

	imin = getIndexOfMinColumn(pathCost,cs1->getSize(),cs2->getSize());

	for(i = 0; i < imin->size();i++)
	{
		ResultatCorrespondance rc2;
		 rc2.correspondanceT1 = new vector<int>();
		rc2.correspondanceT2 = new vector<int>();
		rc2.distance = pathCost[imin->at(i)+2][cs2->getSize()-1]/(3*cs2->getSize());
		itT = 0;
		itM = 0;
		while (itT < cs1->getSize())
		{
			if(itT > imin->at(i) - cs2->getSize() && itT <= imin->at(i))
			{
				rc2.correspondanceT1->push_back(itT);
				rc2.correspondanceT2->push_back(itM);
				itM = itM + 1;
			}
			itT = itT + 1;
		}
		vRc->push_back(rc2);
	}
	itT = 0;
	while (itT < cs1->getSize() + 2)
	{
		delete pathCost[itT];
		itT = itT + 1;
	}
//	free(cost);
    delete pathCost;
	delete imin;
    delete cs1;
    delete cs2;

    return vRc;
}
