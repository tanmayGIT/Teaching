/*!
  \author Abdourahman Aden Hassan
          Bastien Meunier
  \date 24/12/2013
 */
#ifndef COMMANDLINEOUTPUT_H
#define COMMANDLINEOUTPUT_H
#include "Model.h"
#include "Calc.h"
#define EGAL "="
#define SUB  "o"
#define ADDING  "+"
#define SUPPRESS  "-"
#define NO   " "
namespace inout{
class CommandLineOutput
{

    /*!
     * \class CommandLineOutput
     * \brief Cette classe permet de gérer les sorties en ligne de commande
     * \package inout
     */
private:
    model::Sequence * sCLOseq1;

    model::Sequence * sCLOseq2;

    calc::Correspondance * cCLOcor;
    /*!
     * \brief formattageLevensthein
     * Méhode de formatage de la correspondance selon Levensthein
     * \param r un pointeur sur un résutlat
     * \return le resultat formater
     */
    string formattageLevensthein(calc::ResultatCorrespondance * r);
    /*!
     * \brief formattageLCS
     * Méhode de formattage de la correspondance selon LCS
     * \param r un pointeur sur un résutlat
     * \return le resultat formater
     */
    string formattageLCS(calc::ResultatCorrespondance * r);
    /*!
     * \brief formattageType1
     * Méhode de formattage avec le type de format 1 (- pour non correspond et x pour correspond)
     * \param r un pointeur sur un résutlat
     * \return le resultat formater
     */
    string formattageType1(calc::ResultatCorrespondance * r);
	/*!
     * \brief formattageType2
     * Méhode de formattage avec le type de format 2 (dist: ref->target)
     * \param r un pointeur sur un résutlat
     * \return le resultat formater
     */
    string formattageType2(calc::ResultatCorrespondance * r);



    /*!
     * \brief tailleMaxElement
     * Méthode qui permet d'harmoniser l'affichage selon la taille des éléments
     * \param s
     * \return
     */
    unsigned int tailleMaxElement(model::Sequence *s);

    string getSpace(unsigned int size);
public:
    /*!
     * \brief CommandLineOutput
     * Constructeur à 3 arguments de la classe CommandLineOutput
     * \param s1
     * \param s2
     * \param c
     */
    CommandLineOutput( model::Sequence * s1,model::Sequence * s2,calc::Correspondance * c);
    /*!
     * \brief show
     * Méthode d'ecriturte du résultat en console
     */
    void show();

    /*!
     * \brief showInFormat
     * Méthode qui retourne les résultats formatés en string
     */
	string showInFormat();
    /*!
     * \brief format
     * Méthode de formattage de résultats
     * \return
     */
    string format();

    /*!
     * \brief getResult
     * Méthode qui retourne la distance
     * \return la distance minimum des résultats
     */
    float getResult();
};
}
#endif // COMMANDLINEOUTPUT_H
