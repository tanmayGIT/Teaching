/*!
  \author Abdourahman Aden Hassan
  \date 28/12/2013
 */

#if defined __linux__
#include "inouttest.h"
using namespace test;

CppUnit::Test *InOutTest::suite()
{

    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "InOutTest" );
  suiteOfTests->addTest( new CppUnit::TestCaller<InOutTest>(
                                   "checkDocument();",
                                   &InOutTest::checkDocument ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<InOutTest>(
                                   "readCSV();",
                                   &InOutTest::readCSV ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<InOutTest>(
                                   "readEXT();",
                                   &InOutTest::readEXT ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<InOutTest>(
                                   "createPattern();",
                                   &InOutTest::createPattern ) );
    return suiteOfTests;
}

void InOutTest::checkDocument()
{

   inout::SequenceParser *sp = new inout::CSVParser();

    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test1.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test2.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test3.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test4.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test5.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test6.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test7.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test8.csv"), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test9.csv"), exc::SequenceMatchingException);
    sp = new inout::EXTParser();
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/seq_test10.csv"), exc::SequenceMatchingException);

    delete sp;
}

void InOutTest::readCSV()
{

    inout::SequenceParser * sp = new inout::CSVParser();
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/faux.csv"), exc::SequenceMatchingException);
    delete sp;
}

void InOutTest::readEXT()
{

    inout::SequenceParser * sp = new inout::EXTParser();
    CPPUNIT_ASSERT_THROW(sp->readFile((void*)"../tests/faux.ext"), exc::SequenceMatchingException);
    delete sp;
}


void InOutTest::setUp()
{

    ls1 = new std::vector<model::Sequence*>();
    ls2 = new std::vector<model::Sequence*>();
    pp = new inout::ParamParser();
    s1 = new model::Sequence();
    s2 = new model::Sequence();
    ch1 = new model::Character('a');
    n1 = new model::Numeric(12.12);
    cv1 = new model::CharacteristicVector();
    cv2 = new model::CharacteristicVector();
}

void InOutTest::tearDown()
{
    delete n1;
    delete cv1;
    delete cv2;

    delete ls1;
    delete ls2;
    delete pp;
    delete ch1;
    int it = 0;
    while(it<s1->getSize())
    {
        s1->removeElement(0);
        it = it +1;
    }
    delete s1;

    it = 0;
    while(it<s2->getSize())
    {
        s2->removeElement(0);
        it = it +1;
    }
    delete s2;
}



void InOutTest::createPattern()
{
    ls1->push_back(s1);
    ls2->push_back(s2);
    string str = "../tests/essai.xml";
    CPPUNIT_ASSERT_THROW(pp->createPattern(ls1,ls2,(char *)str.c_str()), exc::SequenceMatchingException);
    s1->addElement(ch1);
    CPPUNIT_ASSERT_THROW(pp->createPattern(ls1,ls2,(char *)str.c_str()), exc::SequenceMatchingException);
    s2->addElement(n1);
    CPPUNIT_ASSERT_THROW(pp->createPattern(ls1,ls2,(char *)str.c_str()), exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);
    cv1->addValue(12.12);
    cv1->addValue(13.12);
    cv2->addValue(12.12);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW(pp->createPattern(ls1,ls2,(char *)str.c_str()), exc::SequenceMatchingException);
    cv2->addValue(13.12);
    pp->createPattern(ls1,ls2,(char *)str.c_str());
}

void InOutTest::readParamXML()
{
}

#endif
