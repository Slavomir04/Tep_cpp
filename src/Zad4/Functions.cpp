//
// Created by Sławomir on 23.11.2024.
//

#include "Functions.h"

std::vector<std::string> vecParseStrings(std::string str_line) {
    std::vector<std::string> vec_string;
    std::stringstream ss_stream;
    for(int i=0; i<str_line.size(); i++){
        char c_curr = str_line[i];
        if(c_curr == ' '){
            if(!ss_stream.str().empty()){
                vec_string.push_back(ss_stream.str());
            }
            ss_stream = std::stringstream();
        }else{
            ss_stream<<c_curr;
        }
    }
    return vec_string;
}

CResult<double, CError> rDivide(double d_up, double d_down) {
    if(d_down == 0){
        return CResult<double,CError>::cFail(new CError("dividing by zero is prohibited"));
    }else{
        return CResult<double,CError>::cOk(d_up/d_down);
    }
}

CResult<CTree, CError> rGetTree(std::string str_equasion) {
    CTree c_tree(str_equasion);
    c_tree.dCalculate();


    std::vector<CError*> vec_error;



    if(!c_tree.strFailure().empty()){
            std::vector<std::string> vec_temp = vecParseStrings(c_tree.strFailure());
            for(int i=0; i<vec_temp.size(); i++){
                    Operators::Type e_type = Operators::eStringToType(vec_temp[i]);
                    switch (Operators::iGetArgCount(e_type)) {
                        case 2:
                            vec_error.push_back(new CError(cstZad4::str_operator_error_left + vec_temp[i] + cstZad4::str_operator_error_right));
                            break;
                        case 1:
                            vec_error.push_back(new CError(cstZad4::str_operator_error_left + vec_temp[i] + cstZad4::str_operator_error_right));
                            break;
                        case 0:
                            if(e_type==Operators::variable){
                                vec_error.push_back(new CError(cstZad4::str_variable_error));
                            }else{
                                vec_error.push_back(new CError(cstZad4::str_unknown_error));
                            }
                            break;
                        default:
                            vec_error.push_back(new CError(cstZad4::str_unknown_error));
                            break;
                    }
            }
    }
    if(!c_tree.strCalculationFailure().empty()){
        std::vector<std::string> vec_temp = vecParseStrings(c_tree.strCalculationFailure());
        for(int i=0; i<vec_temp.size(); i++){
            if(vec_temp[i]=="/0"){

                vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_divide_error));
            }else {
                Operators::Type e_type = Operators::eStringToType(vec_temp[i]);
                switch (Operators::iGetArgCount(e_type)) {
                    case 2:
                        vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_operator_error_left + vec_temp[i] + cstZad4::str_operator_error_right));
                        break;
                    case 1:
                        vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_operator_error_left + vec_temp[i] + cstZad4::str_operator_error_right));
                        break;
                    case 0:
                        if (e_type == Operators::variable) {
                            vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_variable_error));
                        } else {
                            vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_unknown_error));
                        }
                        break;
                    default:
                        vec_error.push_back(new CError(cstZad4::str_calculation_prefix+cstZad4::str_unknown_error));
                        break;
                }
            }
        }
    }



    return vec_error.empty() ? CResult<CTree,CError>::cOk(c_tree) :  CResult<CTree,CError>::cFail(vec_error);
}

CResult<int *, int> rTest(int i_x, int i_y) {
    if(i_x + i_y % 2 == 0) {
        return CResult<int*,int>::cFail(new int(21));
    }else {
        return CResult<int*,int>::cOk(new int(12));
    }
}

