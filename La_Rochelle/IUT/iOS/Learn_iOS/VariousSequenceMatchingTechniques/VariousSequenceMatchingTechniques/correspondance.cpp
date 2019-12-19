/*!
  \author Abdourahman Aden Hassan
  \date 21/12/2013
 */

#include "correspondance.h"



using namespace calc;
using namespace std;

Correspondance::Correspondance(void)
{
	pCparam = new Parametrage(0,0);
	isParametrageExtern = false;
}

Correspondance::Correspondance(Parametrage *p)
{
	pCparam = p;
	isParametrageExtern = true;
}

Correspondance::~Correspondance()
{
	if(!isParametrageExtern)
        delete pCparam;
}

void Correspondance::parametrerVectors(model::Sequence *s1, model::Sequence *s2)
{
        int it = 0;
        if(s1->getSize()!=pCparam->getS1Size())
        {
            std::cout<<"s1 taille "<<s1->getSize()<<" param taille "<<pCparam->getS1Size()<<std::endl;
            exc::SequenceMatchingException::genererException("S1 Size size error",PARAMETRE_INVALIDE,__LINE__);
        }

        if(s2->getSize()!=pCparam->getS2Size())
        {
            std::cout<<"s2 taille "<<s2->getSize()<<" param taille "<<pCparam->getS2Size()<<std::endl;
            exc::SequenceMatchingException::genererException("S2 Size size error",PARAMETRE_INVALIDE,__LINE__);
        }
        while(it<s1->getSize())
        {
            if(std::typeid(model::CharacteristicVector)==std::typeid(*s1->getElement(it)))
            {
                model::CharacteristicVector * cp = (model::CharacteristicVector *) s1->getElement(it);
                int it2 = 0;
                if(cp->getSize() != pCparam->getVecCaracSize())
                {
                    exc::SequenceMatchingException::genererException("Characteristic vector size error",PARAMETRE_INVALIDE,__LINE__);
                }
                while(it2<cp->getSize())
                {
                    cp->setValue(it2, cp->getAt(it2)*pCparam->getVecCarac(it2)*pCparam->getS1Weight(it));
                    it2 = it2 +1;
                }
            }
            else if(typeid(model::Numeric)==typeid(*s1->getElement(it)))
            {
                model::Numeric * cpnu =(model::Numeric *)s1->getElement(it);
                cpnu->setValue(cpnu->getValue()*pCparam->getS1Weight(it));
            }
            it = it + 1;
        }

        it = 0;
        while(it<s2->getSize())
        {
            if(typeid(model::CharacteristicVector)==typeid(*s2->getElement(it)))
            {
                model::CharacteristicVector * cp = (model::CharacteristicVector *) s2->getElement(it);
                int it2 = 0;
                if(cp->getSize() != pCparam->getVecCaracSize())
                {
                    exc::SequenceMatchingException::genererException("Characteristic vector size error",PARAMETRE_INVALIDE,__LINE__);
                }
                while(it2<cp->getSize())
                {
                    cp->setValue(it2, cp->getAt(it2)*pCparam->getVecCarac(it2)*pCparam->getS2Weight(it));
                    it2 = it2 +1;
                }
            }
            else if(typeid(model::Numeric)==typeid(*s2->getElement(it))  )
            {
                model::Numeric * cpnu =(model::Numeric *)s2->getElement(it);
                cpnu->setValue(cpnu->getValue()*pCparam->getS2Weight(it));
            }
            it = it + 1;
        }
}

/**
 * Initialise le tableau des distances
 * @param s1 : pointeur sur une sequence
 * @param s2 : pointeur sur la deuxieme sequence
 * @param typesequence : int representant le type des sequence
  *@retrun un tableau des distance entre element des deux sequences
**/
float ** Correspondance::initTabDifference(model::Sequence *s1, model::Sequence *s2)
{
	float ** tabMCdifference = new float*[s1->getSize()];

    int it1 = 0;
    int it2 = 0;
	model::Element *tamp1;
	model::Element *tamp2;
    while(it1<s1->getSize())
    {
		tabMCdifference[it1] = new float[s2->getSize()];
        tamp1 = s1->getElement(it1);
        while(it2<s2->getSize())
        {
            tamp2 = s2->getElement(it2);
			tabMCdifference[it1][it2] = tamp1->distance(tamp1,tamp2);
            it2 = it2 + 1;
        }
        it2 = 0;
        it1 = it1 + 1;
    }
    return tabMCdifference;
}

float Correspondance::calcTab(float **tabDifference, int it1, int it2)
{
    return pCparam->getMatrixWeight(it1,it2)*pCparam->getDistanceWeigh()*(tabDifference[it1][it2]);
}

void Correspondance::freeTabDifference(float **tabDifference, int size1, int size2)
{
    int it1 = 0;
    while(it1<size1)
    {
        delete tabDifference[it1];
        it1 = it1 +1;
    }
   delete tabDifference;
}

vector<int> *Correspondance::getIndexOfMinColumn(float **path, int sizeC, int sizeR){

	vector<int> *vMin = new vector<int>();
	int i_min;
	float seuil = pCparam->getThreshold();
	float min;
	float cost = 0;
	int i = sizeR -1;
	i_min = i;
	min = FLT_MAX;
	if(seuil >= 0)
		min = seuil;
    while(i < sizeC)
    {
		cost = path[i+2][sizeR-1]/(3*sizeR);
		if(cost < min)
		{
			min = cost;
			i_min = i;
			if(seuil < 0){
				vMin->clear();
			}
			else{
				min = seuil;
			}
			vMin->push_back(i_min);
		}
		else if(cost == min){
			i_min = i;
			vMin->push_back(i_min);
		}
		i = i + 1;
    }


	//vMin->push_back(i_min);
	return vMin;
}

vector<int> *Correspondance::getIndexOfMinRow(float **path, int sizeR, int sizeC){

	vector<int> *vMin = new vector<int>();
	int j_min;
	float min;
	float cost = 0;
	int j = 0;
	j_min = j;
	min = FLT_MAX;

    while(j < sizeC)
    {
		cost = path[sizeR-1][j];
		if(cost <= min)
		{
			min = cost;
			j_min = j;
		}
		j = j + 1;
    }
	vMin->push_back(j_min);

	return vMin;
}
