/*!
  \author Abdourahman Aden Hassan
  \date 21/12/2013
  \modified Bastien Meunier
  \date 20/01/2015
 */
#ifndef PARAMPARSER_H
#define PARAMPARSER_H
#include "Calc.h"
#include "sequenceparser.h"

namespace inout{
class ParamParser : public SequenceParser
{
    /*!
     * \class ParamParser
     * \brief Cette classe permet de gerer les conversions de fichiers pour un fichier de parametrage
     * Implements : XMLParser, CSVParser
     * \package inout
     */
public:
	ParamParser() : SequenceParser(){}
	virtual ~ParamParser(){}
    
	virtual void * readFile(void * document);
    /*!
     * \brief createPattern
     * \param list
     * \param filename
     */
    void createPattern(std::vector<model::Sequence *> * list1,std::vector<model::Sequence *> * list2, char * filename);
private:
};
}
#endif // PARAMPARSER_H
