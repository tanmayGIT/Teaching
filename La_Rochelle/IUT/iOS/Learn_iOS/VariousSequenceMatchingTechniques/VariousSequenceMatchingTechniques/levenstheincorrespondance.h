/*!
  \author Abdourahman Aden Hassan
  \date 30/12/2013
 */
#ifndef LEVENSTHEINCORRESPONDANCE_H
#define LEVENSTHEINCORRESPONDANCE_H
#include "correspondance.h"
#define NOCHAR 10000
#define ADD 11000
#define DEL 12000
#define TRANS 13000
#define TRANSEQ 14000
namespace calc{
class LevenstheinCorrespondance : public Correspondance
{
    /*!
     * \class LevenstheinCorrespondance
     * \abstract
     * \package Calc
     * \brief Classe qui effectue la correspondance entre deux séquences en utilisant l'algorithme de Levensthein
     */
protected:
    float fLCdelcost;
    float fLCaddcost;
    float fLCtranscost;
    int isExternParametrage;
public:
    LevenstheinCorrespondance() : Correspondance(){
        fLCaddcost = 1.0;
        fLCdelcost = 1.0;
        fLCtranscost = 1.0;
    };
	LevenstheinCorrespondance(Parametrage * param) : Correspondance(param)
	{
        fLCaddcost = 1.0;
        fLCdelcost = 1.0;
        fLCtranscost = 1.0;
	};
    LevenstheinCorrespondance(float delcost, float addcost, float transcost) : Correspondance(){
        fLCaddcost = delcost;
        fLCdelcost = addcost;
        fLCtranscost = transcost;
    };
    LevenstheinCorrespondance(float delcost, float addcost, float transcost, Parametrage * p): Correspondance(p){
        fLCaddcost = delcost;
        fLCdelcost = addcost;
        fLCtranscost = transcost;
    };

    virtual ~LevenstheinCorrespondance(){};
    vector<ResultatCorrespondance> *correspondre(model::Sequence * s1, model::Sequence * s2);
};
}
#endif // LEVENSTHEINCORRESPONDANCE_H
