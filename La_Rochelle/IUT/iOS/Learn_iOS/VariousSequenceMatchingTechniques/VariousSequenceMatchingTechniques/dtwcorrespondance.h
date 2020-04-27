#ifndef DTWCORRESPONDANCE_H
#define DTWCORRESPONDANCE_H
#include "correspondance.h"

namespace calc{
class DTWCorrespondance : public Correspondance
{
    /*!
     * \class DTWCorrespondance
     * \abstract
     * \package Calc
     * \brief Classe qui effectue la correspondance entre deux séquences en utilisant l'algorithme Dynamic Time Warping
     */
public:
    DTWCorrespondance() : Correspondance(){};
	DTWCorrespondance(Parametrage * param) : Correspondance(param){};
	virtual ~DTWCorrespondance(){};
    vector<ResultatCorrespondance> *correspondre(model::Sequence * s1, model::Sequence * s2);
};
}
#endif // DTWCORRESPONDANCE_H
