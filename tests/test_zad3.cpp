//
// Created by Sławomir on 06.11.2024.
//
#include <gtest/gtest.h>
#include "../src/Zad3/Operators.h"
#include <string>
#include <cmath>

#include "../src/Zad3/CNode.h"
#include "../src/Zad3/CTree.h"
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
    std::string array[10]{"+","-","*","/","sin","cos","1234","012345","avsada",""};
    EXPECT_EQ(Operators::eRecognizeType(array[0]),Operators::PLUS);
    EXPECT_EQ(Operators::eRecognizeType(array[1]),Operators::MINUS);
    EXPECT_EQ(Operators::eRecognizeType(array[2]),Operators::MULL);
    EXPECT_EQ(Operators::eRecognizeType(array[3]),Operators::DIVIDE);
    EXPECT_EQ(Operators::eRecognizeType(array[4]),Operators::SIN);
    EXPECT_EQ(Operators::eRecognizeType(array[5]),Operators::COS);
    EXPECT_EQ(Operators::eRecognizeType(array[6]),Operators::NUMBER);
    EXPECT_EQ(Operators::eRecognizeType(array[7]),Operators::UNKNOWN);
    EXPECT_EQ(Operators::eRecognizeType(array[8]),Operators::UNKNOWN);
    EXPECT_EQ(Operators::eRecognizeType(array[9]),Operators::UNKNOWN);
}
TEST(Operators,iExecuteOperation) {
    double a=5; double b=6;
    Operators::Type op[6]{Operators::PLUS,Operators::MINUS,
        Operators::MULL,Operators::DIVIDE,
        Operators::SIN,Operators::COS};
    double results[6]{a+b,a-b,a*b,a/b,sin(a),cos(a)};
    for(int i=0;i<6;i++)EXPECT_EQ(Operators::dExecuteOperation(op[i],a,b),results[i]);
}

TEST(CTree,dCalculate) {
    int size=7;
    std::string array[size]={"2*2","(2+1)*2","5/0","cos(0) * 15","cos(1+6) / cos(5+1)","16/(5-1-2-2)","5"};
    double results[size]={4,6,5,cos(0)*15,cos(1+6)/cos(5+1),16,5};
    for(int i=0; i<size; i++) {
        CTree t(array[i]);
        EXPECT_EQ(t.dCalculate(),results[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); return RUN_ALL_TESTS();
}