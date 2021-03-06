/*!
  \author Bastien Meunier
  \date 01/01/2014
 */

#include "fsmcorrespondance.h"
#include "typeinfo"
#include "Exc.h"
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstdlib>
#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

using namespace std;
using namespace calc;


vector<calc::ResultatCorrespondance> *calc::FSMCorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{
	//s1 : target
	//s2 : ref
	 // Initialisation
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();
	vector<int> *j_min;
	if( s1->getSize()<s2->getSize())
    {
		delete vRc;
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    // Parametrage
    if(s1->getSize() != pCparam->getS2Size())
    {
        pCparam->setS2Size(s1->getSize());
    }
    if(s2->getSize() != pCparam->getS1Size())
    {
        pCparam->setS1Size(s2->getSize());
    }
    // Check entr�es
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
    parametrerVectors(cs2, cs1);
	//Algorithme
	float ** tabDiff = initTabDifference(cs2,cs1);
	int elasticity = getElasticity(cs2->getSize(),cs1->getSize());
	float weight = getWeight();
	float smallSkipCost = getSmallSkipCost(tabDiff,cs2->getSize(),cs1->getSize());
	float skipCost = getSkipCost(tabDiff,cs2->getSize(),cs1->getSize());
    float ** pathCost = new float*[cs2->getSize()];
	int ** pathRow = new int*[cs2->getSize()];
	int ** pathCol = new int*[cs2->getSize()];

	int itT = 0;
	while(itT<(cs2->getSize()))
    {
		pathCost[itT] = new float[cs1->getSize()];
		pathRow[itT] = new int[cs1->getSize()];
		pathCol[itT] = new int[cs1->getSize()];

		itT = itT + 1;
	}

	int i,j,k;
	int leftBound,rightBound,childBound;
	float skipValue;
	for(i = 0; i < cs2->getSize();i++)
	{
		for(j = 0; j < cs1->getSize();j++)
		{
			pathCost[i][j] = FLT_MAX;
			pathCol[i][j] = INT_MAX;
			pathRow[i][j] = INT_MAX;
		}
	}
	pathCost[0][0] = calcTab(tabDiff,0,0);
	for(j = 1; j < cs1->getSize();j++)
	{
		pathCost[0][j] = calcTab(tabDiff,0,j);
		if(pathCost[0][j-1] == 0)
		{
			pathRow[0][j] = 0;
			pathCol[0][j] = j - 1;
		}
	}

	for(i = 1; i < cs2->getSize();i++)
	{
		if(i == 1)
		{
			leftBound = 0;
			rightBound = cs1->getSize()-1;
		}
		else
		{
			leftBound = std::max(0, (i - 1 - elasticity));
			rightBound = std::min(cs1->getSize()-1, (i - 1 + elasticity));
		}
		for(k = leftBound; k <= rightBound; k++)
		{
			childBound = std::min(cs1->getSize()-1, (k + 1 + elasticity - max(0,k - i + 1)));
			for(j = k; j <= childBound ; j++)
			{
				if(j == k)
					skipValue = smallSkipCost;
				else if (j == k + 1)
					skipValue = 0;
				else
					skipValue = skipCost*weight*(j - k - 1);

				if(pathCost[i][j] > pathCost[i-1][k] + calcTab(tabDiff,i,j) + skipValue)
				{
					pathCost[i][j] = pathCost[i-1][k] + calcTab(tabDiff,i,j) + skipValue;
					pathRow[i][j] = i-1;
					pathCol[i][j] = k;
				}
				if(j > 0)
				{
					if(pathCost[i][j] > pathCost[i][j-1] + calcTab(tabDiff,i,j) + smallSkipCost)
					{
						pathCost[i][j] = pathCost[i][j-1] + calcTab(tabDiff,i,j) + smallSkipCost;
						pathRow[i][j] = i;
						pathCol[i][j] = j-1;
					}
				}
			}
		}
	}

	freeTabDifference(tabDiff,cs2->getSize(),cs1->getSize());
	int tmp,nbJump = 0;
	j_min = getIndexOfMinRow(pathCost,cs2->getSize(),cs1->getSize());
	for(k = 0 ; k < j_min->size();k++)
	{
		ResultatCorrespondance rc;
		rc.correspondanceT1 = new vector<int>();
		rc.correspondanceT2 = new vector<int>();
		i = cs2->getSize()-1;
		j = j_min->at(k);
		nbJump = 0;
		while( (i >= 0) && (j >= 0) && j < cs1->getSize())
		{
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(),i);
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(),j);

			tmp = pathCol[i][j];
			i = pathRow[i][j];
			if(abs(j-tmp) == 0)
				nbJump++;
			else
				nbJump += abs(j-tmp);
			j = tmp;
		}
		rc.distance = pathCost[cs2->getSize()-1][j_min->at(k)]/(rc.correspondanceT1->size());
		vRc->push_back(rc);
	}
	//Fin Algorithme

	i = 0;
	while (i < cs2->getSize())
	{
		delete pathCost[i];
		delete pathCol[i];
		delete pathRow[i];
		i = i + 1;
	}

	delete pathCol;
	delete pathCost;
	delete pathRow;
    delete cs1;
    delete cs2;
	delete j_min;

    return vRc;
}

int FSMCorrespondance::getElasticity(int sizeR,int sizeT)
{
	int elast = pCparam->getiPFsmElesticity();
	if(elast < 0)
	{
		elast = abs(sizeR-sizeT);
	}

	return elast;
}

float FSMCorrespondance::getWeight()
{
	return pCparam->getfPFsmWeight();
}

float FSMCorrespondance::getSmallSkipCost(float ** tabDiff,int sizeR,int sizeT)
{
	float skipValue =  pCparam->getfPFsmSmallSkipCost();
	if(skipValue < 0)
	{
		vector<float> tabMin;
		float average = 0;
		float min = FLT_MAX;
		int i,j;
		for(i = 0; i < sizeR;i++)
		{
			min = FLT_MAX;
			for(j = 0; j < sizeT; j++)
			{
				if(tabDiff[i][j] < min)
					min = tabDiff[i][j];
			}
			tabMin.push_back(min);
			average += min;

		}
		skipValue = average / sizeR;
	}
	return skipValue;
}

float FSMCorrespondance::getSkipCost(float ** tabDiff,int sizeR,int sizeT)
{
	float skipValue =  pCparam->getfPFsmSkipCost();
	if(skipValue < 0)
	{
		vector<float> tabMin;
		float average = 0;
		float stdeviation = 0;
		float min = FLT_MAX;
		int i,j;
		for(i = 0; i < sizeR;i++)
		{
			min = FLT_MAX;
			for(j = 0; j < sizeT; j++)
			{
				if(tabDiff[i][j] < min)
					min = tabDiff[i][j];
			}
			tabMin.push_back(min);
			average += min;

		}
		average = average / sizeR;
		for(i = 0 ;i < tabMin.size();i++)
		{
			stdeviation += (tabMin.at(i)-average) * (tabMin.at(i)-average);
		}
		stdeviation = std::sqrt((stdeviation /sizeR));
		skipValue =  average + 2*stdeviation;
	}
	return skipValue;
}
