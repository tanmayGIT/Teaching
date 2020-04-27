/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#ifndef OPERATORDISTANCE_H
#define OPERATORDISTANCE_H

namespace model{
class Element;
class OperatorDistance
{
    /*! \interface OperatorDistance
        \brief Cette interface définit l'opération de distance.
     * \package model
    */
public:

    virtual ~OperatorDistance() {}
    /*!
     \brief méthode abstraite "distance"
         Cette méthode définit la distance entre deux éléments d'une séquence
     \param eOD1 le premier élément de comparaison
     \param eOD2 le second élément de comparaison
     \return ret la valeur de la distance de comparaison
    */
    virtual float distance(Element *eOD1, Element *eOD2) = 0;
};
}
#endif // OPERATORDISTANCE_H
