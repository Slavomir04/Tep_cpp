//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_OPERATORS_H
#define PROGRAMY_C___TEP_OPERATORS_H
#include <cmath>
#include <string>

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
        UNKNOWN
    };

    static double dExecuteOperation(Type &type, double d_arg1, double d_arg2);
    static Type eRecognizeType(std::string &str_operator);

private:
};


#endif //PROGRAMY_C___TEP_OPERATORS_H
