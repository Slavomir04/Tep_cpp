//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_OPERATORS_H
#define PROGRAMY_C___TEP_OPERATORS_H
#include <cmath>
#include <string>
#include <sstream>
#include "ConstansZad3.h"
class Operators {
public:
    enum Type{
        PLUS,
        MINUS,
        MULL,
        DIVIDE,
        SIN,
        COS,
        NUMBER,
        variable,
        UNKNOWN
    };
    static double dExecuteOperation(Type type, double d_arg1, double d_arg2);
    static Type eRecognizeType(const std::string &str_operator);
    static std::string strTypeToString(const Type &e_type);
    static Operators::Type eStringToType(const std::string &str_type);
    static bool bIsDigit(const std::string &str_number);
    static double dGetDigit(const std::string &str_number);
    static int iGetArgCount(const Operators::Type &type);
    //static std::string strGetStrFromDigit(const double d_value);
private:
};


#endif //PROGRAMY_C___TEP_OPERATORS_H
