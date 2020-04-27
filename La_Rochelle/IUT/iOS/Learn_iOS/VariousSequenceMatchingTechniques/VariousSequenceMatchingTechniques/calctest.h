/*!
  \author Abdourahman Aden Hassan
  \date 20/12/2013
 */
#if defined __linux__
#ifndef CALCTEST_H
#define CALCTEST_H
#include "Exc.h"
#include "Calc.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
namespace test{
class CalcTest : public CppUnit::TestFixture
{
    /*!
     * \class CalcTest
     * \brief Cette classe comprends les tests unitaires du package correspondance
     * \package test
     */
public:
    calc::Parametrage * parTest;
    calc::Parametrage * parTest2;
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

private:
    /*!
     * \brief setS1Weight
     * Test de la fonction setS1Weight
     */
    void setS1Weight();
    /*!
     * \brief setS2Weight
     * Test de la fonction setS1Weight
     */
    void setS2Weight();
    /*!
     * \brief setDistance
     * Test de la fonction setWeightDistance
     */
    void setDistance();
    /*!
     * \brief setMatrixWeight
     */
    void setMatrixWeight();
    /*!
     * \brief setVecCaracWeight
     */
    void setVecCaracWeight();
    /*!
     * \brief setLevensthein
     */
    void setLevensthein();
    /*!
     * \brief setLCS
     */
    void setLCS();
    /*!
     * \brief setDTW
     */
    void setDTW();
    /*!
     * \brief setMVM
     */
    void setMVM();
    /*!
     * \brief setCDP
     */
    void setCDP();
};
}

#endif // CALCTEST_H
#endif
