/*!
  \author Bastien Meunier
  \date 02/12/2014
 */
#ifndef FSMCORRESPONDANCE_H
#define FSMCORRESPONDANCE_H

#include "correspondance.h"
namespace calc{
class FSMCorrespondance : public Correspondance
{

	int getElasticity(int sizeR,int sizeT);
	float getWeight();
	float getSmallSkipCost(float ** tabDiff,int sizeR,int sizeT);
	float getSkipCost(float ** tabDiff,int sizeR,int sizeT);


public:
	FSMCorrespondance() : Correspondance(){};
	FSMCorrespondance(Parametrage * param) : Correspondance(param){};
	virtual ~FSMCorrespondance(){};

	vector<ResultatCorrespondance> *correspondre(model::Sequence * starget, model::Sequence * sRef);
};
}
#endif
