/*!
  \author Meunier Bastien
  \date 24/12/2013
 */
#ifndef EXTPARSERCLASSMATCHING_H
#define EXTPARSERCLASSMATCHING_H
#include "sequenceparser.h"
#include <string>
using namespace std;
namespace inout {
class EXTParserClassMatchnig : public SequenceParser
{
    /*! \interface EXTParser
        \brief Cette interface d�finit le parsage CSV de notre application en fichier XML
     * \package inout
    */
public:
	EXTParserClassMatchnig() : SequenceParser(){}
	virtual ~EXTParserClassMatchnig(){}
    /*!
     * \brief readEXT
     * \param doc fichier EXT contenant la s�quence
     * \return
     */
    void * readFile(void * doc);
};

}
#endif

