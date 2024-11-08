//
// Created by Sławomir on 06.11.2024.
//

#include "Operators.h"

double Operators::dExecuteOperation(Type &type, double d_arg1, double d_arg2) {
    double d_result=0;
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
    }
    return d_result;
}

Operators::Type Operators::eRecognizeType(std::string &str_operator) {
    Type e_result=UNKNOWN;
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
            default:
                break;
        }
    }else if(str_operator.size()==3){
        if(str_operator == "cos"){
            e_result=COS;
        }else if(str_operator == "sin"){
            e_result=SIN;
        }
    }else if(str_operator.size()>0){
        bool b_is_number=true;
        if(!(str_operator[0]>='1' && str_operator[0]<='9')){
            b_is_number=false;
        }
        for(int i=1; i<str_operator.size()&&b_is_number; i++) {
            if(!(str_operator[i]>='0' && str_operator[i]<='9')){
                b_is_number=false;
            }
        }
        if(b_is_number) {
            e_result=NUMBER;
        }
    }
    return e_result;
}

