/*!
  \author Abdourahman Aden Hassan
  \date 24/12/2013
 */
#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "sequenceparser.h"
namespace inout {

class XMLParser : public SequenceParser
{
    /*! \interface XMLParser
        \brief Cette interface définit le parsage XML de notre application
     * \package inout
    */
public:
	XMLParser() : SequenceParser(){}
	virtual ~XMLParser(){}
    /*!
     * \brief parseXML
     * \param doc fichier XML contenant un objet
     * \return
     */
    void * readFile(void * document);
};

}
#endif // XMLPARSER_H
