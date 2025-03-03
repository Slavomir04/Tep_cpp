//
// Created by Sławomir on 12.11.2024.
//

#ifndef PROGRAMY_C___TEP_CLIZAD3_H
#define PROGRAMY_C___TEP_CLIZAD3_H
#include <iostream>
#include <strstream>
#include "CTree.h"
#include "Operators.h"
#include "ConstansZad3.h"
class CLIZad3 {
public:
    CLIZad3();
    ~CLIZad3();
    void vStart();
private:
    bool b_loop;
    CTree c_Tree;

    char* pc_variables_array;
    double* pc_values_array;
    const int i_size_variables_array;
    int i_index_last_variables_array;


    void vFirstInit();
    void vExecute(const std::string &str_line);
    void vExecuteCommand(const std::string &command);

    void vEnterFormula(const std::string &str_formula);
    void vJoinFormula(const std::string &str_formula);
    void vShowVars();
    void vComp(const std::string* pc_array,const int i_size_array);

    void vPrint();
    void vPrintFormulaFailure(std::string &str_failure);
    void vPrintCalculationFailure(std::string &str_failure);
    void vPrintCompFailure();
    void vPrintUnkownCommand();
    void vAddVariable(char c_variable,double d_value);
    bool bSetVariable(int i_index,double d_value);
    bool bSetVariable(char c_variable,double d_value);
    bool bContainsVariable(char c_variable);
    void vUpdateTree();

};


#endif //PROGRAMY_C___TEP_CLIZAD3_H
