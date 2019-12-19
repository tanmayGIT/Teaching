/*!
  \author Abdourahman Aden Hassan
  \date 24/12/2013
  \modified Bastien Meunier
  \date 20/01/2015
 */
#ifndef SEQUENCEPARSER_H
#define SEQUENCEPARSER_H
#include "Calc.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex.h>
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

#define CHARACTER 0
#define NUMERIC 1
#define VECTOR 2
#define CASSEP 0
#define CASINT 1
#define CASVAL 2

#ifdef __linux__
#include <uuid/uuid.h>
#endif // defined

namespace inout {
class SequenceParser
{
    /*!
     * \class SequenceParser
     * \brief Cette classe permet de gerer les conversions de fichiers pour une Séquence
     * Implements : XMLParser, CSVParser
     * \package inout
     */
public:
    SequenceParser();
    virtual ~SequenceParser();
    /*!
     * \brief read
     * \param document fichier contenant un objet ou les séquences
     * \return
     */
	virtual void * readFile(void * document) = 0;
	vector<string> classes;
	int vecteur;

protected:
    /*!
     * \brief checkDocument permet de vérifier la validité du document
     * \param list liste de valeurs
     * \exception invalid file
     */
    int checkDocument(vector<string> list);
    vector<char *> listPoubelle;
};
}
#endif // SEQUENCEPARSER_H
