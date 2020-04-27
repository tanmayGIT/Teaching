/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include "operatordistance.h"
using namespace std;
namespace model{
class Element : public OperatorDistance
{
    /*!
     * \class Element
     * \brief Cette classe abstraite définit la forme d'un élément de séquence.
     * Implements : OperatorDistance
     * \abstract
     * \package model
     */
    protected:
    /*!< L'id de l'objet*/
    string quidEid;
public:
    Element(){}
    virtual ~Element() {}
    /*!
    *  \brief Accesseur
    *  Accesseur de la classe Element
    *  \return id : la valeur de l'identifiant de l'objet
    */
    string getUid(){return quidEid;}
    /*!
    *  \brief Modifieur
    *  Modifieur de la classe Element
    *  \return id : la valeur de l'identifiant de l'objet
    */
    void setUid(string q){quidEid = q;}
    /*!
     \brief méthode abstraite "distance"
         Cette méthode définit la distance entre deux éléments d'une séquence
     \param eOD1 le premier élément de comparaison
     \param eOD2 le second élément de comparaison
     \return ret la valeur de la distance de comparaison
    */
    virtual float distance(Element *eOD1, Element *eOD2) = 0;
    /*!
     * \brief toString
     * Méthode d'affichage de l'élément
     * \return
     */
    virtual string toString() = 0;
    /*!
     * \brief copy
     * Méthode de copie d'un élément alloué sur la pile
     * \param s
     * \return
     */
    virtual Element * copy() = 0;

};
}
#endif // ELEMENT_H
