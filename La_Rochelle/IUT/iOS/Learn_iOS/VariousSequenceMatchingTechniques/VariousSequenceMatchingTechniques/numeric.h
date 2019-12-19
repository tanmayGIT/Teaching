/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#ifndef NUMERIC_H
#define NUMERIC_H
#include "element.h"

namespace model{
class Numeric : public Element
{

    /*!
     * \class Numeric
     * \brief Cette classe définit un élément de type numérique pour une séquence.
     * Inherits Element
     * \package model
     */
protected:
    /*!< La valeur du nombre*/
    float fNvalue;
public:
    /*!
    *  \brief Constructeur
    *  Constructeur par défaut de la classe Numeric
    */
    Numeric();
    /*!
    *  \brief Constructeur
    *  Constructeur à un argument de la classe Numeric
    *  \param value la valeur de l'objet
    */
    Numeric(float value);
    /*!
    *  \brief Constructeur de recopie
    *  Constructeur de recopie de la classe Numeric
    *  \param copy : l'objet caractère à copier
    */
    Numeric(Numeric const & copy);
    /*!
    *  \brief Accesseur getValue
    *  Accesseur de la classe Numeric
    *  \return ret : la valeur de l'attribut value
    */
    float getValue();
    /*!
    *  \brief modifieur setValue
    *  Modifieur de la classe Numeric
    *  \param value : l'attribut value
    */
    void setValue(float value);

    /*!
     \brief méthode abstraite "distance"
         Cette méthode définit la distance entre deux éléments d'une séquence
     \param eOD1 le premier élément de comparaison
     \param eOD2 le second élément de comparaison
     \return ret la valeur de la distance de comparaison
    */
    float distance(Element *eOD1, Element *eOD2);
    /*!
     * \brief toString
     * Méthode d'affichage de l'élément
     * \return
     */
    string toString();
    /*!
     * \brief copy
     * Méthode de copie d'un élément alloué sur la pile
     * \return
     */
     Element * copy();
};
}
#endif // NUMERIC_H
