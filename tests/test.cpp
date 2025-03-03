//
// Created by Sławomir on 06.11.2024.
//
#include <gtest/gtest.h>
#include "../src/Zad3/Operators.h"
#include <string>
#include <cmath>
#include "../src/Zad3/CNode.h"
#include "../src/Zad4/CResult.h"
#include "../src/Zad4/CError.h"
TEST(Operators, eRecognizeType) {
    /*
     PLUS,
    MINUS,
    MULL,
    DIVIDE,
    SIN,
    COS,
    NUMBER,
    UNKNOWN
    */
    const int size = 11;
    std::string array[size]{"+","-","*","/","sin","cos","1234","012345","avsada","","0"};
    EXPECT_EQ(Operators::eRecognizeType(array[0]),Operators::PLUS);
    EXPECT_EQ(Operators::eRecognizeType(array[1]),Operators::MINUS);
    EXPECT_EQ(Operators::eRecognizeType(array[2]),Operators::MULL);
    EXPECT_EQ(Operators::eRecognizeType(array[3]),Operators::DIVIDE);
    EXPECT_EQ(Operators::eRecognizeType(array[4]),Operators::SIN);
    EXPECT_EQ(Operators::eRecognizeType(array[5]),Operators::COS);
    EXPECT_EQ(Operators::eRecognizeType(array[6]),Operators::NUMBER);
    EXPECT_EQ(Operators::eRecognizeType(array[7]),Operators::NUMBER);
    EXPECT_EQ(Operators::eRecognizeType(array[8]),Operators::UNKNOWN);
    EXPECT_EQ(Operators::eRecognizeType(array[9]),Operators::UNKNOWN);
    EXPECT_EQ(Operators::eRecognizeType(array[10]),Operators::NUMBER);
}
TEST(Operators,iExecuteOperation) {
    double a=5; double b=6;
    Operators::Type op[6]{Operators::PLUS,Operators::MINUS,
        Operators::MULL,Operators::DIVIDE,
        Operators::SIN,Operators::COS};
    double results[6]{a+b,a-b,a*b,a/b,sin(a),cos(a)};
    for(int i=0;i<6;i++)EXPECT_EQ(Operators::dExecuteOperation(op[i],a,b),results[i]);
}

TEST(Operators,bIsDigit) {
    EXPECT_EQ(Operators::bIsDigit("5"),true);
    EXPECT_EQ(Operators::bIsDigit("0"),true);
    EXPECT_EQ(Operators::bIsDigit("10"),true);
    EXPECT_EQ(Operators::bIsDigit("10123.123121231"),true);
    EXPECT_EQ(Operators::bIsDigit("0.123121231"),true);
    EXPECT_EQ(Operators::bIsDigit("0.0"),true);
    EXPECT_EQ(Operators::bIsDigit(".0"),false);
    EXPECT_EQ(Operators::bIsDigit("."),false);
    EXPECT_EQ(Operators::bIsDigit(""),false);
    EXPECT_EQ(Operators::bIsDigit("0000.01"),false);
    EXPECT_EQ(Operators::bIsDigit("0001"),false);
    EXPECT_EQ(Operators::bIsDigit("000"),false);
}




TEST(CNode,destructor){
    CNode* array[5]{new CNode(Operators::PLUS,0),new CNode(Operators::PLUS,0),
                    new CNode(Operators::PLUS,0),new CNode(Operators::PLUS,0),new CNode(Operators::PLUS,0)};
    for(int i=0; i<5-1; i++){
        array[i]->pcSetLeft(array[i+1]);
    }
    delete array[0];
    for(int i=0; i<5; i++){
        EXPECT_EQ(array[i],nullptr);
    }
}

TEST(CResult,constructor){
    CResult<double,CError> c_1(5);
    CResult<double,CError> copy_1(5);
    ASSERT_EQ(c_1.cGetValue(),copy_1.cGetValue());
    ASSERT_EQ(c_1.bIsSuccess(),copy_1.bIsSuccess());

    CResult<double,CError> c_2 = CResult<double, CError>::cOk(5.0);
    CResult<double,CError> copy_2 = c_2;
    ASSERT_EQ(c_2.cGetValue(),copy_2.cGetValue());
    ASSERT_EQ(c_2.bIsSuccess(),true);
    ASSERT_EQ(c_2.bIsSuccess(),copy_2.bIsSuccess());


}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); return RUN_ALL_TESTS();
}