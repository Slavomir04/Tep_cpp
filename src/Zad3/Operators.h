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
        UNKNOWN
    };

    static int iExecuteOperation(Type &type,int i_a,int i_b){
        int i_result=0;
        switch (type) {
            case PLUS:
                i_result = i_a + i_b;
                break;
            case MINUS:
                i_result = i_a - i_b;
                break;
            case MULL:
                i_result = i_a * i_b;
                break;
            case DIVIDE:
                i_result = i_a / i_b;
                break;
            case SIN:
                i_result = (int) sin(i_a);
                break;
            case COS:
                i_result = (int) cos(i_a);
                break;
        }
        return i_result;
    }

    static Type eRecognizeType(std::string &str_operator){
        Type e_result=UNKNOWN;
        if(str_operator.size()==1){
            char c = str_operator[0];
            switch (c) {
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
        }
        return e_result;
    }
private:
};


#endif //PROGRAMY_C___TEP_OPERATORS_H
