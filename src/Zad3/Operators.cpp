//
// Created by Sławomir on 06.11.2024.
//

#include "Operators.h"

double Operators::dExecuteOperation(Type type, double d_arg1, double d_arg2) {
    double d_result;
    switch (type) {
        case PLUS:
            d_result = d_arg1 + d_arg2;
        break;
        case MINUS:
            d_result = d_arg1 - d_arg2;
        break;
        case MULL:
            d_result = d_arg1 * d_arg2;
        break;
        case DIVIDE:
            if(d_arg2==0) {
                d_result = d_arg1;
            }else {
                d_result = d_arg1 / d_arg2;
            }
        break;
        case SIN:
            d_result =  sin(d_arg1);
        break;
        case COS:
            d_result =  cos(d_arg1);
        break;
        default:
            d_result=0;
            break;
    }
    return d_result;
}

Operators::Type Operators::eRecognizeType(const std::string &str_operator) {
    Type e_result;
    if(str_operator.size()==1){
        switch (str_operator[0]) {
            case '+':
                e_result=PLUS;
            break;
            case '-':
                e_result=MINUS;
            break;
            case '*':
                e_result=MULL;
            break;
            case '/':
                e_result=DIVIDE;
            break;
            case '(':
                e_result=BRACKET_LEFT;
                break;
            case ')':
                e_result=BRACKET_RIGHT;
                break;
            default:
                e_result = ('0'<=str_operator[0] && str_operator[0]<='9')?NUMBER:UNKNOWN;
                break;
        }
    }else if(str_operator.size()==3){
        if(str_operator == "cos"){
            e_result=COS;
        }else if(str_operator == "sin") {
            e_result = SIN;
        }else{
            e_result=UNKNOWN;
        }
    }else if(!str_operator.empty() && '0'<=str_operator[0] && str_operator[0]<='9' && bIsDigit(str_operator)){
        e_result=NUMBER;
    }else{
        e_result=UNKNOWN;
    }


    return e_result;
}

std::string Operators::strTypeToString(const Operators::Type &e_type) {
    std::string result;
    switch(e_type){
        case PLUS:
            result="+";
            break;
        case MINUS:
            result='-';
            break;
        case MULL:
            result="*";
            break;
        case DIVIDE:
            result="/";
            break;
        case SIN:
            result="sin";
            break;
        case COS:
            result="cos";
            break;
        case NUMBER:
            result="NUMBER";
            break;
        default:
            result="UNKNOWN";
    }
    return result;
}

bool Operators::bIsDigit(const std::string &str_number) {
    try{
        double  d = std::stod(str_number);
        return true;
    }catch(...){
        return false;
    }
}

double Operators::dGetDigit(const std::string &str_number) {
    return std::stod(str_number);
}

int Operators::iGetArgCount(const Operators::Type &type) {
    int i_result;
    if(type==PLUS || type==MINUS || type==MULL || type==DIVIDE){
        i_result=2;
    }else if(type==SIN || type==COS){
        i_result=1;
    }else if(type==NUMBER){
        i_result=0;
    } else{
        i_result=-1;
    }
    return i_result;
}

