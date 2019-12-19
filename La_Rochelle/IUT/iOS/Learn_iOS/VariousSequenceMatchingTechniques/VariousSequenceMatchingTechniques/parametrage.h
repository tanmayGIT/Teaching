/*!
  \author Abdourahman Aden Hassan
  \date 21/12/2013
 */
#ifndef PARAMETRAGE_H
#define PARAMETRAGE_H
#include "Model.h"
#include <vector>

using namespace std;
namespace calc{
class Parametrage
{
    /*! \class Parametrage
     *  \package Calc
     *  \brief Classe de parametrage de la correspondance (ou alignement)
     */
protected:
    /*!< La taille de la séquence 1*/
    unsigned int iPsizeS1;
    /*!< La taille de la séquence 2*/
    unsigned int iPsizeS2;
    /*!< La taille des vecteurs de caractérstiques*/
    unsigned int iPsizeVecCarac;
    /*!< Le coefficient appliqué à la distance, 1 par défaut*/
    float vPweigtDistance;
    /*!< Le coefficient appliqué à chaque élément de la première séquence dans le cas de calculs de distances entre 2 séquences, 1 par défaut*/
    vector<float> *vPweightS1;
    /*!< Le coefficient appliqué à chaque élément de la seconde séquence dans le cas de calculs de distances entre 2 séquences, 1 par défaut*/
    vector<float> *vPweightS2;
    /*!< Le coefficient appliqué à chaque élément des vecteurs de caracteristiques, 1 par défaut*/
    vector<float> *vPweightVecCarac;
    /*!< Le coefficient appliqué à la matrice entre 2 séquences, 1 par défaut*/
    vector<vector<float>*> *vPweightMatrice;
	/*!<Le seuil de résultat du CDP, -1 par défaut*/
	float fPThreshold;
	/*!<Les cout de déplacement du levenshtein, 1 par défaut*/
	vector<float> *vPLevenshteinCost;
	/*!<La valeur de division pour l'elasticité du MvM, 10 par défaut*/
	float fPDivElastic;
	/*!<La valeur de l'elasticité du FSM, -1 par défaut*/
	int iPFsmElesticity;
	/*!<La valeur du poids W du FSM, 1 par défaut*/
	float fPFsmWeight;
	/*!<La valeur du petit skip cost du FSM, -1 par défaut*/
	float fPFsmSmallSkipCost;
	/*!<La valeur du grand skip cost du FSM, -1 par défaut*/
	float fPFsmSkipCost;



public:

    /*!
     \brief Constructeur
         Constructeur à deux arguments de la classe Parametrage
     \param sizeS1 la taille de la première séquence
     \param sizeS2 la taille de la seconde séquence
    */
    Parametrage(unsigned int sizeS1, unsigned int sizeS2);

    /*!
     \brief Constructeur
         Constructeur à trois arguments de la classe Parametrage
     \param sizeS1 la taille de la première séquence
     \param sizeS2 la taille de la seconde séquence
     \param sizeVecCarac la taille des vecteurs de caractéristiques
    */
    Parametrage(unsigned int sizeS1,unsigned int sizeS2,unsigned int sizeVecCarac);
    /*!
     * \brief Destructeur
     */
    ~Parametrage();
    /*!
     \brief Methode setS1Weight
         Méthode de fixation de poids pour un élément de la séquence 1
     \param index Indice de l'élément
     \param value Valeur du poids
     \exception Si l'index dépasse la taille de la séquence
     \exception Si la valeur du poids n'est pas comprise entre 0 et 1
    */
    void setS1Weight(unsigned int index, float value);
    /*!
     \brief Methode setS2Weight
         Méthode de fixation de poids pour un élément de la séquence 2
     \param index Indice de l'élément
     \param value Valeur du poids
     \exception Si l'index dépasse la taille de la séquence
     \exception Si la valeur du poids n'est pas comprise entre 0 et 1
    */
    void setS2Weight(unsigned int index, float value);
    /*!
     \brief Methode setS1Weight
         Méthode de fixation de poids pour un élément des vecteurs de caractéristiques
     \param index Indice de l'élément
     \param value Valeur du poids
     \exception Si l'index dépasse la taille de la séquence
     \exception Si la valeur du poids n'est pas comprise entre 0 et 1
     \exception S'il n'y a pas de taille de vecteur de caracteristique définie
    */
    void setVecCaracWeight(unsigned int index, float value);
    /*!
     \brief Methode setMatrixWeight
         Méthode de fixation de poids pour un élément de la matrice
     \param index1 Indice de l'élément 1
     \param index2 Indice de 'élémeent 2
     \param value Valeur du poids
     \exception Si un des index dépasse la taille de la séquence
     \exception Si la valeur du poids n'est pas comprise entre 0 et 1
    */
    void setMatrixWeight(unsigned int index1,unsigned int index2, float value);

    /*!
     \brief Methode setDistanceWeight
         Méthode de fixation de poids pour la distance finale
     \param value Valeur du poids
     \exception Si la valeur du poids n'est pas comprise entre 0 et 1
    */
    void setDistanceWeight(float value);
    /*!
     \brief Modifieur setS1Size
         Méthode de redéfinition de la taille de la première séquence
     \param value Taille de la séquence 1
    */
    void setS1Size(unsigned int value);
    /*!
     * \brief getS1Size
     * \return
     */
    int getS1Size();
    /*!
     \brief Modifieur setS2Size
         Méthode de redéfinition de la taille de la seconde séquence
     \param value Taille de la séquence 2
    */
    void setS2Size(unsigned int value);
    /*!
     * \brief getS1Size
     * \return
     */
    int getS2Size();
    /*!
     \brief Modifieur setVecCaracSize
         Méthode de redéfinition de la taille des vecteurs de caractéristiques
     \param value Taille des vecteurs de caractéristiques
    */
    void setVecCaracSize(unsigned int value);
    /*!
     * \brief getVecCaracSize
     * \return
     */
    int getVecCaracSize();
    /*!
     * \brief getS1Weight
     * \param index
     * \return
     */
    float getS1Weight(unsigned int index);
    /*!
     * \brief getS2Weight
     * \param index
     * \return
     */
    float getS2Weight(unsigned int index);
    /*!
     * \brief getMatrixWeight
     * \param i1
     * \param i2
     * \return
     */
    float getMatrixWeight(unsigned int i1, unsigned int i2);
    /*!
     * \brief getDistanceWeigh
     * \return
     */
    float getDistanceWeigh();
    /*!
     * \brief getVecCarac
     * \param index
     * \return
     */
    float getVecCarac(unsigned int index);

    /*!
     * \brief getThreshold
     * \return threhold
     */
	float getThreshold();

	/*!
     \brief Modifieur setThreshold
         Méthode de redéfinition du seuil de selection du CDP
     \param threshold seuil
    */
	void setThreshold(float threshold);

    /*!
     * \brief getLevenshteinCost
     * \return un de cout de modification
     */
	float getLevenshteinCost(unsigned int index);

	/*!
     \brief Modifieur setLevenshteinCost
         Méthode de redéfinition des cout de Levenshtein
     \param addCost
     \param delCost
     \param transCost
    */
	void setLevenshteinCost(float addCost,float delCost,float transCost);

    /*!
     * \brief getMvMDivElastic
     * \return le nombre utiliser pour obtenir l'elasticite
     */
	float getMvMDivElastic();

	/*!
     \brief Modifieur setMvMDivElastic
         Méthode de redéfinition du diviseur de l'elasticite de MVM
     \param elest diviseur
    */
	void setMvMDivElastic(float elast);

	/*!
	* \brief getfPFsmSkipCost
     * \return le skipCost du FSM
     */
	float getfPFsmSkipCost();

	/*!
     \brief Modifieur setfPFsmSkipCost
         Méthode de redéfinition du skipCost du FSM
     \param w
    */
	void setfPFsmSkipCost(float skipValue);
	/*!
	* \brief getfPFsmSmallSkipCost
     * \return le smallSkipCost du FSM
     */
	float getfPFsmSmallSkipCost();

	/*!
     \brief Modifieur setfPFsmSmallSkipCost
         Méthode de redéfinition du smallSkipCost du FSM
     \param w
    */
	void setfPFsmSmallSkipCost(float skipValue);
	
	/*!
     * \brief getfPFsmWeight
     * \return le poids W du FSM
     */
	float getfPFsmWeight();

	/*!
     \brief Modifieur setfPFsmWeight
         Méthode de redéfinition du poids W du FSM
     \param w
    */
	void setfPFsmWeight(float w);
	/*!
     * \brief getfPFsmElesticity
     * \return un l'elaticité du FSM
     */
	int getiPFsmElesticity();

	/*!
     \brief Modifieur setfPFsmElesticity
         Méthode de redéfinition del'elasticity de FSM
     \param elasticity
    */
	void setiPFsmElesticity(int elasticity);
};
}
#endif // PARAMETRAGE_H
