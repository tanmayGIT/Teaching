#include "calctest.h"
#include "math.h"
#if defined __linux__
using namespace test;

CppUnit::Test *CalcTest::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("CalcTest");

    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setS1Weight",
                                   &test::CalcTest::setS1Weight ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setS2Weight",
                                   &test::CalcTest::setS2Weight ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setDistanceWeight",
                                   &test::CalcTest::setDistance ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setMatrixWeight",
                                   &test::CalcTest::setMatrixWeight ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setVecCaracWeight",
                                   &test::CalcTest::setVecCaracWeight ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setLevensthein();",
                                   &test::CalcTest::setLevensthein ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setLCS();",
                                   &test::CalcTest::setLCS ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setDTW();",
                                   &test::CalcTest::setDTW ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setMVM();",
                                   &test::CalcTest::setMVM ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<test::CalcTest>(
                                   "setCDP();",
                                   &test::CalcTest::setCDP ) );
    return suiteOfTests;
}

void CalcTest::setS1Weight()
{
    CPPUNIT_ASSERT_THROW(parTest->setS1Weight(-1,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setS1Weight(11,1), exc::SequenceMatchingException);
    parTest->setS1Weight(8,0);
    CPPUNIT_ASSERT(parTest->getS1Weight(8)==0);
    CPPUNIT_ASSERT(parTest->getS1Weight(9)==1);
    CPPUNIT_ASSERT_THROW(parTest->getS1Weight(11), exc::SequenceMatchingException);
}

void CalcTest::setS2Weight()
{

    CPPUNIT_ASSERT_THROW(parTest->setS2Weight(-1,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setS2Weight(11,1), exc::SequenceMatchingException);
    parTest->setS2Weight(8,0);
    CPPUNIT_ASSERT(parTest->getS2Weight(8)==0);
    CPPUNIT_ASSERT(parTest->getS2Weight(9)==1);
    CPPUNIT_ASSERT_THROW(parTest->getS2Weight(11), exc::SequenceMatchingException);
}

void CalcTest::setDistance()
{
    CPPUNIT_ASSERT_THROW(parTest->setDistanceWeight(-1);, exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setDistanceWeight(2);, exc::SequenceMatchingException);
    parTest->setDistanceWeight(0.5);
    CPPUNIT_ASSERT(parTest->getDistanceWeigh()==0.5);
}

void CalcTest::setMatrixWeight()
{
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(-1,1,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(1,-1,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(11,1,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(1,11,1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(0,0,-1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setMatrixWeight(0,0,2), exc::SequenceMatchingException);
    parTest->setMatrixWeight(0,0,0.5);
    CPPUNIT_ASSERT(parTest->getMatrixWeight(0,0)==0.5);
    CPPUNIT_ASSERT(parTest->getMatrixWeight(0,1)==1);
}

void CalcTest::setVecCaracWeight()
{
    CPPUNIT_ASSERT_THROW(parTest->getVecCarac(0), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest2->getVecCarac(11), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest->setVecCaracWeight(0,0), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest2->setVecCaracWeight(0,-1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(parTest2->setVecCaracWeight(0,11), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_NO_THROW(parTest2->setVecCaracWeight(0,0.5));
    parTest->setVecCaracSize(10);
    CPPUNIT_ASSERT_NO_THROW(parTest->setVecCaracWeight(0,0.5));
    CPPUNIT_ASSERT(parTest->getVecCarac(0)==0.5);
    CPPUNIT_ASSERT(parTest->getVecCarac(1)==1);
}

void CalcTest::setLevensthein()
{
    model::Sequence * s1 = new model::Sequence();
    model::Sequence * s2 = new model::Sequence();
    model::Character * c1 = new model::Character('l');
    model::Character * c2 = new model::Character('e');
    model::Character * c3 = new model::Character('v');
    model::Character * c4 = new model::Character('e');
    model::Character * c5 = new model::Character('n');
    model::Character * c6 = new model::Character('s');
    model::Character * c7 = new model::Character('h');
    model::Character * c8 = new model::Character('t');
    model::Character * c9 = new model::Character('e');
    model::Character * c10 = new model::Character('i');
    model::Character * c11 = new model::Character('n');
    model::Character * c12 = new model::Character('m');
    model::Character * c13 = new model::Character('e');
    model::Character * c14 = new model::Character('i');
    model::Character * c15 = new model::Character('l');
    model::Character * c16 = new model::Character('e');
    model::Character * c17 = new model::Character('n');
    model::Character * c18 = new model::Character('s');
    model::Character * c19 = new model::Character('t');
    model::Character * c20 = new model::Character('e');
    model::Character * c21 = new model::Character('i');
    model::Character * c22 = new model::Character('n');
    model::Numeric * n1 = new model::Numeric();
    calc::LevenstheinCorrespondance * lc = new calc::LevenstheinCorrespondance();
    s1->addElement(c1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s2->addElement(n1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);

    model::CharacteristicVector * cv1 = new model::CharacteristicVector();
    model::CharacteristicVector * cv2 = new model::CharacteristicVector();
    cv1->addValue(12);
    cv2->addValue(1);
    cv2->addValue(23);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(c1);
    s1->addElement(c2);
    s1->addElement(c3);
    s1->addElement(c4);
    s1->addElement(c5);
    s1->addElement(c6);
    s1->addElement(c7);
    s1->addElement(c8);
    s1->addElement(c9);
    s1->addElement(c10);
    s1->addElement(c11);
    s2->addElement(c12);
    s2->addElement(c13);
    s2->addElement(c14);
    s2->addElement(c15);
    s2->addElement(c16);
    s2->addElement(c17);
    s2->addElement(c18);
    s2->addElement(c19);
    s2->addElement(c20);
    s2->addElement(c21);
    s2->addElement(c22);
    calc::ResultatCorrespondance rc;
    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    CPPUNIT_ASSERT(rc.distance==4);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(0)==13000);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(1)==14001);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(0)==13000);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(1)==14001);

    delete n1;
    delete cv1;
    delete cv2;
    delete rc.correspondanceT1;
    delete rc.correspondanceT2;
//    delete rc;
    delete lc;
    delete s1;
    delete s2;
}

void CalcTest::setLCS()
{
    model::Sequence * s1 = new model::Sequence();
    model::Sequence * s2 = new model::Sequence();
    model::Character * c1 = new model::Character('g');
    model::Character * c2 = new model::Character('a');
    model::Character * c3 = new model::Character('c');
    model::Character * c4 = new model::Character('a');
    model::Character * c5 = new model::Character('g');
    model::Character * c6 = new model::Character('c');
    model::Character * c7 = new model::Character('a');
    model::Character * c8 = new model::Character('t');
    model::Numeric * n1 = new model::Numeric();
    model::CharacteristicVector * cv1 = new model::CharacteristicVector();
    model::CharacteristicVector * cv2 = new model::CharacteristicVector();
    calc::LCScorrespondance* lc = new calc::LCScorrespondance();
    calc::ResultatCorrespondance rc;

    s1->addElement(c1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s2->addElement(n1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);

    cv1->addValue(12);
    cv2->addValue(1);
    cv2->addValue(23);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(c1);
    s1->addElement(c2);
    s1->addElement(c3);
    s2->addElement(c4);
    s2->addElement(c5);
    s2->addElement(c6);
    s2->addElement(c7);
    s2->addElement(c8);
    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    CPPUNIT_ASSERT(rc.distance==2);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(0)==1);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(1)==1);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(2)==0);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(0)==0);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(1)==1);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(2)==0);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(3)==1);
    CPPUNIT_ASSERT(rc.correspondanceT2->at(4)==0);
    delete n1;
    delete cv1;
    delete cv2;
    delete lc;
    delete rc.correspondanceT1;
    delete rc.correspondanceT2;
    //delete rc;
    delete s1;
    delete s2;
}

void CalcTest::setDTW()
{
    model::Sequence * s1 = new model::Sequence();
    model::Sequence * s2 = new model::Sequence();
    model::Character * c1 = new model::Character('g');
    model::Numeric * n1 = new model::Numeric(1);
    model::Numeric * n2 = new model::Numeric(1);
    model::Numeric * n3 = new model::Numeric(2);
    model::Numeric * n4 = new model::Numeric(3);
    model::Numeric * n5 = new model::Numeric(2);
    model::Numeric * n6 = new model::Numeric(0);
    model::Numeric * n7 = new model::Numeric(0);
    model::Numeric * n8 = new model::Numeric(1);
    model::Numeric * n9 = new model::Numeric(1);
    model::Numeric * n10 = new model::Numeric(2);
    model::Numeric * n11 = new model::Numeric(3);
    model::Numeric * n12 = new model::Numeric(2);
    model::Numeric * n13 = new model::Numeric(1);
    model::CharacteristicVector * cv1 = new model::CharacteristicVector();
    model::CharacteristicVector * cv2 = new model::CharacteristicVector();
    calc::DTWCorrespondance* lc = new calc::DTWCorrespondance();
    calc::ResultatCorrespondance rc;


    s1->addElement(c1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s2->addElement(n1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    cv1->addValue(12);
    cv2->addValue(1);
    cv2->addValue(23);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);

    s1->addElement(n1);
    s1->addElement(n2);
    s1->addElement(n3);
    s1->addElement(n4);
    s1->addElement(n5);
    s1->addElement(n6);
    s2->addElement(n7);
    s2->addElement(n8);
    s2->addElement(n9);
    s2->addElement(n10);
    s2->addElement(n11);
    s2->addElement(n12);
    s2->addElement(n13);
    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    CPPUNIT_ASSERT(rc.distance == (float) (sqrt(2)));
    CPPUNIT_ASSERT(rc.correspondanceT1->at(0)==0 && rc.correspondanceT2->at(0)==0);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(1)==0 && rc.correspondanceT2->at(1)==1);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(2)==1 && rc.correspondanceT2->at(2)==2);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(3)==2 && rc.correspondanceT2->at(3)==3);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(4)==3 && rc.correspondanceT2->at(4)==4);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(5)==4 && rc.correspondanceT2->at(5)==5);
    CPPUNIT_ASSERT(rc.correspondanceT1->at(6)==5 && rc.correspondanceT2->at(6)==6);
    delete cv1;
    delete cv2;
    delete rc.correspondanceT1;
    delete rc.correspondanceT2;
 //   delete rc;
    delete lc;
    delete s1;
    delete s2;
}

void CalcTest::setMVM()
{
    model::Sequence * s1 = new model::Sequence();
    model::Sequence * s2 = new model::Sequence();
    model::Character * c1 = new model::Character('g');
    model::Numeric * n1 = new model::Numeric(1);
    model::Numeric * n2 = new model::Numeric(2);
    model::Numeric * n3 = new model::Numeric(8);
    model::Numeric * n4 = new model::Numeric(6);
    model::Numeric * n5 = new model::Numeric(8);
    model::Numeric * n6 = new model::Numeric(1);
    model::Numeric * n7 = new model::Numeric(2);
    model::Numeric * n8 = new model::Numeric(9);
    model::Numeric * n9 = new model::Numeric(3);
    model::Numeric * n10 = new model::Numeric(3);
    model::Numeric * n11 = new model::Numeric(5);
    model::Numeric * n12 = new model::Numeric(9);
    model::CharacteristicVector * cv1 = new model::CharacteristicVector();
    model::CharacteristicVector * cv2 = new model::CharacteristicVector();
    calc::MvmCorrespondance* lc = new calc::MvmCorrespondance();
    calc::ResultatCorrespondance rc;

    std::cout<<"OK"<<std::endl;

    s1->addElement(c1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s2->addElement(n1);
    CPPUNIT_ASSERT_THROW(lc->correspondre(s1,s2), exc::SequenceMatchingException);
    cv1->addValue(12);
    cv2->addValue(1);
    cv2->addValue(23);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW( lc->correspondre(s1,s2), exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(n1);
    s1->addElement(n2);
    s1->addElement(n3);
    s1->addElement(n4);
    s1->addElement(n5);
    s2->addElement(n6);
    s2->addElement(n7);
    s2->addElement(n8);
    s2->addElement(n9);
    s2->addElement(n10);
    s2->addElement(n11);
    s2->addElement(n12);

    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    std::cout<<" Distance "<<rc.distance<<std::endl;
    CPPUNIT_ASSERT(fabs(rc.distance - sqrt(3)) < 0.00001);

    delete c1;
    delete cv1;
    delete cv2;
    delete lc;
    delete rc.correspondanceT1;
    delete rc.correspondanceT2;
   // delete rc;
    delete s1;
    delete s2;
}

void CalcTest::setCDP()
{
    model::Sequence * s1 = new model::Sequence();
    model::Sequence * s2 = new model::Sequence();
    model::Numeric * n1 = new model::Numeric(1);
    model::Numeric * n2 = new model::Numeric(2);
    model::Numeric * n8 = new model::Numeric(8);
    model::Numeric * n16 = new model::Numeric(16);
    model::Numeric * n9 = new model::Numeric(9);
    model::Numeric * n25 = new model::Numeric(25);
    model::Numeric * n37 = new model::Numeric(37);
    model::CharacteristicVector * cv1 = new model::CharacteristicVector();
    model::CharacteristicVector * cv2 = new model::CharacteristicVector();
    calc::CDPCorrespondance* lc = new calc::CDPCorrespondance();
    calc::ResultatCorrespondance rc;

    std::cout<<"CDP OK"<<std::endl;

    cv1->addValue(12);
    cv2->addValue(1);
    cv2->addValue(23);
    s1->addElement(cv1);
    s2->addElement(cv2);
    CPPUNIT_ASSERT_THROW( lc->correspondre(s1,s2),exc::SequenceMatchingException);
    s1->removeElement(0);
    s2->removeElement(0);
    s1->addElement(n1);
    s1->addElement(n2);
    s1->addElement(n8);
    s1->addElement(n16);
    s1->addElement(n16);

    s2 = s1->copy();

    std::cout<<" ele "<< s1->getSize()<<std::endl;
    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    std::cout<<" Distance "<<rc.distance<<std::endl;
    CPPUNIT_ASSERT(rc.distance == (float) (0.0));
    s2->removeElement(4);
    s2->removeElement(3);
    s2->removeElement(2);
    s2->addElement(n9);
    s2->addElement(n16);
    s2->addElement(n9);
    s2->addElement(n25);
    s2->addElement(n37);

    std::cout<<" ele "<< s2->toString()<<std::endl;
    CPPUNIT_ASSERT_NO_THROW(rc = lc->correspondre(s1,s2)->at(0));
    std::cout<<" Distance "<<rc.distance<<std::endl;
    CPPUNIT_ASSERT(rc.distance == (float) (1.6));
    delete cv1;
    delete cv2;
    delete lc;
    delete s1;
    delete s2;
}

void CalcTest::setUp()
{
    parTest = new calc::Parametrage(10,10);
    parTest2 = new calc::Parametrage(10,10,10);
}

void CalcTest::tearDown()
{
    delete parTest;
    delete parTest2;
}

#endif
