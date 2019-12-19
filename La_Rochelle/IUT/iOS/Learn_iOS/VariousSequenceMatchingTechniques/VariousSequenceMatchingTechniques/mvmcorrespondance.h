/*!
  \author Abdourahman Aden Hassan
  \date 01/01/2014
 */
#ifndef MVMCORRESPONDANCE_H
#define MVMCORRESPONDANCE_H

#include "correspondance.h"
#if defined _WIN32 || defined _WIN64
            // Windows Includes Here
	inline int round(float x) { return (int) (floor(x + 0.5)); }
#endif
namespace calc{
class MvmCorrespondance : public Correspondance
{
private:
    int isExternParametrage;
public:
    /*!
     * \brief MvmCorrespondance
     */
    MvmCorrespondance() : Correspondance(){};
	MvmCorrespondance(Parametrage * param) : Correspondance(param){};
	virtual ~MvmCorrespondance(){};
    vector<ResultatCorrespondance> *correspondre(model::Sequence * s1, model::Sequence * s2);
};
}
#endif // MVMCORRESPONDANCE_H
