/*!
  \author Meunier Bastien
  \date 24/12/2013
 */
#ifndef EXTPARSER_H
#define EXTPARSER_H
#include "sequenceparser.h"
#include <string>
namespace inout {
using namespace std;
class EXTParser : public SequenceParser
{
    /*! \interface EXTParser
        \brief Cette interface définit le parsage CSV de notre application en fichier XML
     * \package inout
    */
public:
	EXTParser() : SequenceParser(){}
	virtual ~EXTParser(){}
    /*!
     * \brief readEXT
     * \param doc fichier contenant la séquence
     * \return
     */
    void * readFile(void * doc);
};

}
#endif // CSVPARSER_H

