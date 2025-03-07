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
            if(d_arg2==0) { //FAIL
                d_result = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
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
    if(!bIsDigit(str_operator)) {
        if (str_operator.size() == 1) {
            switch (str_operator[0]) {
                case '+':
                    e_result = PLUS;
                    break;
                case '-':
                    e_result = MINUS;
                    break;
                case '*':
                    e_result = MULL;
                    break;
                case '/':
                    e_result = DIVIDE;
                    break;
                default:
                    e_result = UNKNOWN;
                    break;
            }
            if(('a' <= str_operator[0] && str_operator[0]<='z') || ('A' <= str_operator[0] && str_operator[0]<='Z')){
                e_result = variable;
            }
        } else if (str_operator.size() == 3) {
            if (str_operator == "cos") {
                e_result = COS;
            } else if (str_operator == "sin") {
                e_result = SIN;
            } else {
                e_result = UNKNOWN;
            }
        }
    }else{
        e_result = NUMBER;
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
        case variable:
            result="variable";
            break;
        default:
            result="UNKNOWN";
    }
    return result;
}
Operators::Type Operators::eStringToType(const std::string &str_type) {
    Operators::Type e_type;
    if(str_type == "+"){
        e_type=Operators::Type::PLUS;
    }else if(str_type == "-"){
        e_type=Operators::Type::MINUS;
    }else if(str_type == "*"){
        e_type=Operators::Type::MULL;
    }else if(str_type == "/"){
        e_type=Operators::Type::DIVIDE;
    }else if(str_type == "sin"){
        e_type=Operators::Type::SIN;
    }else if(str_type == "cos"){
        e_type=Operators::Type::COS;
    }else if(str_type == "NUMBER"){
        e_type=Operators::Type::NUMBER;
    }else if(str_type == "variable"){
        e_type=Operators::Type::variable;
    }else{
        e_type=Operators::Type::UNKNOWN;
    }
    return e_type;
}

bool Operators::bIsDigit(const std::string &str_number) {
    bool b_dot_seen = false;
    bool b_digit_seen = false;
    int i_start = 0;


    if (str_number[0] == '-') {
        if (str_number.size() == 1) {
            return false;
        }
        i_start = 1;
    }

    for (int i = i_start; i < str_number.size(); ++i) {
        if (std::isdigit(str_number[i])) {
            b_digit_seen = true;
        } else if (str_number[i] == '.') {
            if (b_dot_seen) {
                return false;
            }
            b_dot_seen = true;
        } else {
            return false;
        }
    }

    return b_digit_seen;
}

double Operators::dGetDigit(const std::string &str_number) {
    //return std::stod(str_number);
    std::stringstream ss_stream;
    ss_stream<<str_number;
    double d_result=0;
    ss_stream>>d_result;
    return d_result;
}

int Operators::iGetArgCount(const Operators::Type &type) {
    int i_result;
    if(type==PLUS || type==MINUS || type==MULL || type==DIVIDE){
        i_result=2;
    }else if(type==SIN || type==COS){
        i_result=1;
    }else if(type==NUMBER || type==variable){
        i_result=0;
    } else{
        i_result=-1;
    }
    return i_result;
}




