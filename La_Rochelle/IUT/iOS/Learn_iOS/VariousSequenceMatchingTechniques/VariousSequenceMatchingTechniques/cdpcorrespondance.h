/*!
  \author Bastien Meunier
  \date 02/12/2014
  \package Calc
  \class CDPCorrespondance
  \extends Correspondance
  \brief Class for matchnig with Continuous Dynamic Programming algorithm
 */
#ifndef CDPCORRESPONDANCE_H
#define CDPCORRESPONDANCE_H

#include "correspondance.h"
namespace calc{
class CDPCorrespondance : public Correspondance
{

private:
     /*!
     * \brief min3
     *  Get the minimum from 3 float
     * \param f1 :the first number
     * \param f2 :the second number
     * \param f3 :the third number
     * \return the minimum
     */
   float min3(float f1, float f2, float f3);

public:
    /*!
    * \brief CDPCorrespondance, CDPCorrespondance(Parametrage *param)
    * Class constructors, inherit Correspondance
    */
	CDPCorrespondance() : Correspondance(){};
	CDPCorrespondance(Parametrage * param) : Correspondance(param){};
	virtual ~CDPCorrespondance(){};

	vector<ResultatCorrespondance> *correspondre(model::Sequence * sTarget, model::Sequence * sRef);
};
}
#endif
