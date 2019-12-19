/*!
  \author Abdourahman Aden Hassan
  \date 21/12/2013
 */
#ifndef CORRESPONDANCE_H
#define CORRESPONDANCE_H
#include "parametrage.h"
#include "Model.h"
#include <vector>
#include <typeinfo>
#include "Exc.h"
#include "cfloat"
#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2
using namespace std;
namespace calc{
/*!
 * \struct ResultatCorrespondance
 * \brief Structure de données qui contient le résultat d'une correspondance à savoir :
 * -- une correspondance--
 * Soit 2 séquence a et b de taille n et m.
 * Deux tableau numériques t1 et t2 respectivement de taille n et m:
 * Quelquesoit 0<i<n /  0<t1[i]<m  si correspondance avec un élément de b
 *                      t1[i] = -1 sinon
 * Quelquesoit 0<j<m /  0<t2[i]<n  si correspondance avec un élément de a
 *                      t2[i] = -1 sinon
 * -- la distance optimale --
 * La distance selon la correspondance effectuée et les poids appliqués
 */
typedef struct{
    vector<int> * correspondanceT1;
    vector<int> * correspondanceT2;
    float distance;
}ResultatCorrespondance;
class Correspondance
{
    /*!
     * \class Correspondance
     * \abstract
     * \package Calc
     * \brief Classe abstraite qui effectue la correspondance entre deux séquences
     */
protected:
        bool isParametrageExtern;
        Parametrage * pCparam;
        /*!
         * \brief parametrerVectors
         * \param s1
         * \param s2
         */
        void parametrerVectors(model::Sequence * s1, model::Sequence * s2);

     /*! \brief initTabDifference
     * Fonction d'initialisation  et de calcules du tableau de différence
     * \param s1 la première séquence
     * \param s2 la seconde séquence
     * \return le tableau des differences
     */
    float **  initTabDifference(model::Sequence * s1, model::Sequence * s2);
    /*!
     * \brief calcTab
     * Fonction retournat la distance entre deux elements des sequences
     * \param tabDifference le tableau
     * \param it1
     * \param it2
     * \return la distance ponderée avec les parametres
     */
    float calcTab(float ** tabDifference, int it1, int it2);

    /*!
     * \brief freeTabDifference
     * Fonction de libération du tableau de différence
     * \param tabDifference
     * \param size1
     * \param size2
     */
    void freeTabDifference(float ** tabDifference, int size1, int size2);

        /*!
     * \brief getIndiceOfMin
     *  Get the line index(es) of the minimum(s) value(s) in the last column of a matrix
     * \param path :the matrix to look for (path[1..size1][1..size2])
     * \param size1 :the number of line in the matrix
     * \param size2 :the number of column in the matrix
     *  \return an array of index(es)
     */
	vector<int> *getIndexOfMinColumn(float ** path, int size1, int size2);

	vector<int> *getIndexOfMinRow(float ** path, int size1, int size2);

    public:
        Correspondance();
        Correspondance(Parametrage *param);
        virtual ~Correspondance();
        /*!
         * \brief Method correspondre
         * Méthode abstraite de correspondance entre deux séquences
         * \param s1 la première séquence
         * \param s2 la seconde séquence
         * \return res le résultat de la correspondance
         */
        virtual vector<ResultatCorrespondance> *correspondre(model::Sequence * sTarget, model::Sequence * sRef) = 0;
};


}
#endif // CORRESPONDANCE_H
