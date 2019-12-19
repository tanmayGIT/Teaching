/*!
  \author Abdourahman Aden Hassan
  \date 28/12/2013
 */
#if defined __linux__
#ifndef INOUTTEST_H
#define INOUTTEST_H

#include "Exc.h"
#include "InOut.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
namespace test{
class InOutTest : public CppUnit::TestFixture
{
    /*!
     * \class InOutTest
     * \brief Cette classe comprends les tests unitaires du package correspondance
     * \package test
     */
public:
    /*!
     * \brief setUp
     */
    void setUp();
    /*!
     * \brief tearDown
     */
    void tearDown();
    /*!
     * \brief do_all_test
     * Méthode qui lance tous les tests
     */
    static CppUnit::Test *suite();
protected:

    std::vector<model::Sequence*> * ls1;
    std::vector<model::Sequence*> * ls2;
    inout::ParamParser * pp;
    model::Sequence * s1;
    model::Sequence * s2;
    model::Character * ch1;
    model::Numeric * n1;
    model::CharacteristicVector * cv1;
    model::CharacteristicVector * cv2;
    /*!
     * \brief checkDocument
     * Test de la fonction Check Document
     */
    void checkDocument();
    /*!
     * \brief readCSV
     * Test de la fonction Read CSV
     */
    void readCSV();

     void readEXT();
    /*!
     * \brief createPattern
     * Test de la fonction Create Pattern
     */
    void createPattern();
    /*!
     * \brief readParamXML
     * Test de la fonction Read XML pour un fichier de parametrage
     */
    void readParamXML();

};
}

#endif // INOUTTEST_H
#endif
