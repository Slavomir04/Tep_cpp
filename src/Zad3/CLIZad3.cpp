//
// Created by Sławomir on 12.11.2024.
//

#include "CLIZad3.h"

CLIZad3::CLIZad3() : i_size_variables_array(cstZad3::i_DEFAULT_VARIABLES_ARRAY_SIZE) {
    vFirstInit();
}

CLIZad3::~CLIZad3() {
    delete[] pc_variables_array;
    delete[] pc_values_array;
}

void CLIZad3::vFirstInit() {
    b_loop = true;
    this->pc_variables_array = new char[i_size_variables_array];
    this->pc_values_array = new double [i_size_variables_array];
    this->i_index_last_variables_array=0;
}

void CLIZad3::vStart() {
    while (b_loop){
        std::string line;
        printf("write:");
        //std::cin>>line;
        std::getline(std::cin,line);
        vExecute(line);
    }
}

void CLIZad3::vExecute(const std::string &str_line) {

    std::stringstream ss_stream;
    bool b_shifted= false;
    for(int i=0; i<str_line.size(); i++){
        char c = str_line[i];
        if(c == ' '){
            if(!b_shifted)ss_stream<<' ';
            b_shifted= true;
        }else{
            b_shifted= false;
            ss_stream<<c;
        }
    }
    std::string str_command = ss_stream.str();
    vExecuteCommand(str_command);
}

void CLIZad3::vExecuteCommand(const std::string &command) {
    if(!command.empty()) {
        const int i_array_size = command.size();
        std::string *pc_array = new std::string[i_array_size];
        int i_last_index=0;

        std::stringstream ss_stream;
        for(int i=0; i<command.size(); i++){
            char c = command[i];
            if(c==' '){
                if(!ss_stream.str().empty()){
                    pc_array[i_last_index++]=ss_stream.str();
                }
                ss_stream = std::stringstream();
            }else{

                ss_stream<<c;
            }
        }

        if(!ss_stream.str().empty()){
            pc_array[i_last_index++]=ss_stream.str();
        }

        if(i_last_index!=0){
            if(pc_array[0] == cstZad3::str_COMP_COMMAND){
                vComp(pc_array,i_last_index);
            }else if(pc_array[0] == cstZad3::str_ENTER_FORMULA_COMMAND){
                std::string str_formula;
                for(int i=1; i<i_last_index; i++){
                    if(pc_array[i].size()==1 && ('a'<=pc_array[i][0] && pc_array[i][0]<='z' || 'A'<=pc_array[i][0] && pc_array[i][0]<='Z')){
                        vAddVariable(pc_array[i][0],cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    }
                    str_formula+=pc_array[i]+" ";
                }
                vEnterFormula(str_formula);
            }else if(pc_array[0] == cstZad3::str_JOIN_FORMULA_COMMAND){
                std::string str_formula;
                for(int i=1; i<i_last_index; i++){
                    if(pc_array[i].size()==1 && ('a'<=pc_array[i][0] && pc_array[i][0]<='z' || 'A'<=pc_array[i][0] && pc_array[i][0]<='Z')){
                        vAddVariable(pc_array[i][0],cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    }
                    str_formula+=pc_array[i]+" ";
                }
                vJoinFormula(str_formula);
            }else if(pc_array[0] == cstZad3::str_PRINT_COMMAND){
                vPrint();
            }else if(pc_array[0] == cstZad3::str_SHOW_VARS_COMMAND){
                vShowVars();
            }else if(pc_array[0] == cstZad3::str_EXIT_COMMAND){
                b_loop= false;
            }else{
                vPrintUnkownCommand();
            }
        }

        delete[] pc_array;
    }
}

void CLIZad3::vEnterFormula(const std::string &str_formula) {

    this->c_Tree = CTree(str_formula);
    std::string str_failure_temp = c_Tree.strFailure();
    vPrintFormulaFailure(str_failure_temp);

    vUpdateTree();
}

void CLIZad3::vJoinFormula(const std::string &str_formula) {
        this->c_Tree = c_Tree + CTree(str_formula);
        std::string str_failure_temp = c_Tree.strFailure();
        vPrintFormulaFailure(str_failure_temp);
        vUpdateTree();
}

void CLIZad3::vShowVars() {
    if(i_index_last_variables_array==0){
        printf("no variables\n");
    }
    for(int i=0; i<i_index_last_variables_array; i++){
        printf("%c: %.2f\n",pc_variables_array[i],pc_values_array[i]);
    }
}

void CLIZad3::vComp(const std::string* pc_array, const int i_size_array) {
    if(i_index_last_variables_array<i_size_array-1){
        vPrintCompFailure();
    }else if(i_size_array>1){
        bool b_out_of_bound = false;
        for (int i = 1; i < i_size_array && !b_out_of_bound; i++) {

            if (Operators::bIsDigit(pc_array[i])) {

                double d_value = Operators::dGetDigit(pc_array[i]);
                if (!bSetVariable(i-1, d_value)) {
                    b_out_of_bound = true;
                }

            }

        }
    }
    vUpdateTree();
}

void CLIZad3::vPrint() {
    printf("str: %s\n",c_Tree.str_str().c_str());
    printf("str completed: %s\n",c_Tree.str_str(true).c_str());
    printf("calculation: %.8f\n",c_Tree.dCalculate());
    std::string str_failure_temp = c_Tree.strCalculationFailure();
    vPrintCalculationFailure(str_failure_temp);
}

void CLIZad3::vPrintFormulaFailure(std::string &str_failure) {
    std::stringstream ss_stream;
    for(int i=0; i<str_failure.size(); i++){
        char c = str_failure[i];
        if(c==' '){
            const std::string str_temp = ss_stream.str();
            Operators::Type e_type = Operators::eStringToType(str_temp);
            int i_fill = Operators::iGetArgCount(e_type);
            switch (i_fill) {
                case 2:
                    printf("blad operatora  (%s) w formule\n",str_temp.c_str());
                    break;
                case 1:
                    printf("blad funkcji (%s) w formule \n",str_temp.c_str());
                    break;
                default:
                    if(e_type == Operators::variable){
                        printf("blad zmiennej (%s) w formule \n",str_temp.c_str());
                    } else{
                        printf("nieznany znak (%s) w formule\n",str_temp.c_str());
                    }
            }
            ss_stream.flush();
        }else{
            ss_stream<<c;
        }
    }
    if(!ss_stream.str().empty()){
        const std::string str_temp = ss_stream.str();
        Operators::Type e_type = Operators::eStringToType(str_temp);
        int i_fill = Operators::iGetArgCount(e_type);
        switch (i_fill) {
            case 2:
                printf("blad operatora  (%s) w formule\n", str_temp.c_str());
                break;
            case 1:
                printf("blad funkcji (%s) w formule \n", str_temp.c_str());
                break;
            default:
                if (e_type == Operators::variable) {
                    printf("blad zmiennej (%s) w formule \n", str_temp.c_str());
                } else {
                    printf("nieznany znak (%s) w formule\n", str_temp.c_str());
                }
        }
    }
}

void CLIZad3::vPrintCalculationFailure(std::string &str_failure) {
    std::stringstream ss_stream;
    for(int i=0; i<str_failure.size(); i++){
        char c = str_failure[i];
        if(c==' '){
            const std::string str_temp = ss_stream.str();
            Operators::Type e_type = Operators::eStringToType(str_temp);
            int i_fill = Operators::iGetArgCount(e_type);
            switch (i_fill) {
                case 2:
                    printf("blad operatora  (%s) przy liczeniu, bledne argumenty zamieniaja sie w %.8f\n",str_temp.c_str(),cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    break;
                case 1:
                    printf("blad funkcji (%s) przy liczeniu,bledny argument zamieni sie w %.8f \n",str_temp.c_str(),cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    break;
                default:
                    if(e_type == Operators::variable){
                        printf("blad zmiennej (%s) przy liczeniu, zamiana na: %.8f \n",str_temp.c_str(),cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    } else{
                        printf("nieznany znak (%s) przy liczeniu, zamiana na: %.8f\n",str_temp.c_str(),cstZad3::d_DEFAULT_VALUE_OF_VARIABLE);
                    }
            }
            ss_stream = std::stringstream();
        }else{
            ss_stream<<c;
        }
    }
    if(!ss_stream.str().empty()){
        const std::string str_temp = ss_stream.str();
        Operators::Type e_type = Operators::eStringToType(str_temp);
        int i_fill = Operators::iGetArgCount(e_type);
        switch (i_fill) {
            case 2:
                printf("blad operatora  (%s) przy liczeniu\n",str_temp.c_str());
                break;
            case 1:
                printf("blad funkcji (%s) przy liczeniu \n",str_temp.c_str());
                break;
            default:
                if(e_type == Operators::variable){
                    printf("blad zmiennej (%s) przy liczeniu \n",str_temp.c_str());
                } else{
                    printf("nieznany znak (%s) przy liczeniu\n",str_temp.c_str());
                }
        }
    }
}



void CLIZad3::vPrintCompFailure() {
    printf("wartosci jest wiecej niz zmiennych!\n");
}
void CLIZad3::vPrintUnkownCommand() {
    printf("Nie znana komenda!\n");
}

void CLIZad3::vAddVariable(char c_variable,double d_value){
        if(i_index_last_variables_array<i_size_variables_array && !bContainsVariable(c_variable)){
            pc_variables_array[i_index_last_variables_array]=c_variable;
            pc_values_array[i_index_last_variables_array]=d_value;
            i_index_last_variables_array++;
        }
}

bool CLIZad3::bSetVariable(int i_index, double d_value) {
    bool b_result= false;
    if(i_index<i_index_last_variables_array){
        pc_values_array[i_index]=d_value;
        b_result= true;
    }
    return b_result;
}
bool CLIZad3::bSetVariable(char c_variable, double d_value) {
    bool b_result;
    if(i_index_last_variables_array==0){
        b_result= false;
    }else{
        b_result= false;
        for(int i=0; i<i_index_last_variables_array&&!b_result; i++){
            if(pc_variables_array[i]==c_variable){
                pc_values_array[i]=d_value;
                b_result= true;
            }
        }
    }
    return b_result;
}

bool CLIZad3::bContainsVariable(char c_variable) {
    bool b_result;
    if(i_index_last_variables_array==0){
        b_result= false;
    }else{
        b_result= false;
        for(int i=0; i<i_index_last_variables_array&&!b_result; i++){
            if(pc_variables_array[i]==c_variable){
                b_result= true;
            }
        }
    }
    return b_result;
}



void CLIZad3::vUpdateTree() {
    if(i_index_last_variables_array>0){
        for(int i=0; i<i_index_last_variables_array; i++){
            c_Tree.bSetVariable(pc_variables_array[i],pc_values_array[i]);
        }
    }
}





