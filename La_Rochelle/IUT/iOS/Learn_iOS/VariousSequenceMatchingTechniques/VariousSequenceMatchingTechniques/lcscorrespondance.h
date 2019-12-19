/*!
  \author Abdourahman Aden Hassan
  \date 30/12/2013
 */
#ifndef LCSCORRESPONDANCE_H
#define LCSCORRESPONDANCE_H

#include "correspondance.h"

namespace calc{
class LCScorrespondance : public Correspondance
{
protected:
    int isExternParametrage;
public:

    /*!
     * \class LCSCorrespondance
     * \abstract
     * \package Calc
     * \brief Classe qui effectue la correspondance entre deux séquences en utilisant l'algorithme LCS
     */
    /*!
     * \brief LCScorrespondance
     */
   LCScorrespondance() : Correspondance(){};
	LCScorrespondance(Parametrage * param) : Correspondance(param){};
	virtual ~LCScorrespondance(){};
    vector<ResultatCorrespondance> *correspondre(model::Sequence * s1, model::Sequence * s2);
};
}

#endif // LCSCORRESPONDANCE_H
