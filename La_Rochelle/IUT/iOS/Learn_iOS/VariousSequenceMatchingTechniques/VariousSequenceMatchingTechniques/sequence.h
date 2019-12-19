/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <vector>
#include "element.h"
#include "characteristicvector.h"
#include "character.h"
#include "numeric.h"

namespace model{
using namespace std;
class Sequence
{
    /*! \class Sequence
        \brief Cette classe définit une séquence et donc une liste d'éléments
     * \package model
    */
protected:
    /*!< La liste des éléments*/
    vector<Element*> * vSlist;
    /*!< L'ID de la séquence*/
    string qSid;
public:

    /*!
    *  \brief Constructeur
    *  Constructeur par défaut de la classe Séquence
    */
    Sequence();
    /*!
     * \brief Destructeur
     * Destructeur de la classe Séquence
     */
    ~Sequence();
    /*!
    *  \brief Constructeur de recopie
    *  Constructeur de recopie de la classe Sequence
    *  \param copy : l'objet caractère à copier
    */
    Sequence(Sequence const & copy);
    /*!
    *  \brief Méthode d'ajout
    *  Méthode d'ajout de la classe Sequence
    *  \param elt l'élément à ajouter
    */
    void addElement(Element * elt);
    /*!
    *  \brief Méthode de suppression
    *  Méthode de suppression de la classe Sequence
    *  \param index l'index de l'élément à supprimer
    */
    void removeElement(unsigned int index);
    /*!
    *  \brief Accesseur Element
    *  Accesseur de la classe Sequence pour un Element
    *  \return id : la valeur de l'identifiant de l'objet
    */
    Element * getElement(unsigned int index);
    /*!
     * \brief getSize
     * Permet de connaitre la taille de la liste d'éléments
     * \return ret entier contenant la taille
     */
    int getSize();
    /*!
    *  \brief Accesseur UID
    *  Accesseur de la classe Sequence pour l'UID
    *  \return id : la valeur de l'identifiant de l'objet
    */

    string getUid();
    /*!
     * \brief Modifieur
     * Modifieur de la classe Séquence
     * \param q
     */
    void setUid(string q);
    /*!
     * \brief toString
     * \return
     */
    string toString();
    /*!
     * \brief copy
     * Méthode de création d'une copie d'un objet alloué sur la pile
     * \return
     */
    Sequence * copy();
};
}
#endif // SEQUENCE_H
