//
// Created by Sławomir on 06.11.2024.
//

#include "CTree.h"

CTree::CTree(const std::string &str_equation) {
    vFirstInit();
    vMakeTree(str_equation);
    vCheckFailure(pc_root);
}
CTree::CTree(const CTree &cOther) {
    vFirstInit();
    vCopyHelper(cOther.pc_root, *this);
    vCheckFailure(pc_root);
}
CTree::CTree(CTree &&cOther) noexcept{
    this->pc_root = cOther.pc_root;
    this->str_failure_ = cOther.str_failure_;
    this->str_Calculation_Failure_ = cOther.str_Calculation_Failure_;

    cOther.pc_root = nullptr;
    cOther.str_failure_=std::string();
    cOther.str_Calculation_Failure_=std::string();
}

CTree::~CTree() {
    delete pc_root;
}



void CTree::vFirstInit() {
    this->pc_root = nullptr;
    this->str_failure_="";
}

double CTree::dCalculate() {
    double d_result;
    this->str_Calculation_Failure_="";
    if(pc_root== nullptr){
        d_result=0;
    }else{
        d_result = dCalculationHelper(pc_root);
    }
    return d_result;
}



void CTree::vMakeTree(const std::string &str_equasion) { //wszystko rodzielone spacja
    delete pc_root;
    pc_root= nullptr;
    std::stringstream  ss_stream;



    for(int i=0; i < str_equasion.size(); i++){
        if(str_equasion[i] == ' '){
            if(!ss_stream.str().empty()) {
                Operators::Type type = Operators::eRecognizeType(ss_stream.str());
                int i_fill_size = Operators::iGetArgCount(type);
                CNode *pi_temp= nullptr;

                /*
                if (i_fill_size > 0) {
                    pi_temp = new CNode(type);
                } else if (i_fill_size == 0) {
                    double d_value = Operators::dGetDigit(ss_stream.str());
                    pi_temp = new CNode(type, d_value);
                }
                */

                if (i_fill_size > 0) {
                    pi_temp = new CNode(type);
                } else if (i_fill_size == 0){
                    if(Operators::bIsDigit(ss_stream.str())) {
                        double d_value = Operators::dGetDigit(ss_stream.str());
                        pi_temp = new CNode(type, d_value);
                    }else{
                        pi_temp = new CNode(type);
                        if(type == Operators::Type::variable){
                            pi_temp->vSetName(ss_stream.str()[0]);
                        }
                    }
                }

                if (!bAddNode(pi_temp)) {
                   // str_failure_ += Operators::strTypeToString(type) + " ";
                    vAddFailure(type);
                    delete pi_temp;
                }
            }
            ss_stream = std::stringstream();
        }else{
            ss_stream << str_equasion[i];
        }
    }

    //last adding
    if(!ss_stream.str().empty()) {
       // printf("last: '%s'\n",ss_stream.str().c_str());
        Operators::Type type = Operators::eRecognizeType(ss_stream.str());
        int i_fill_size = Operators::iGetArgCount(type);
        CNode *pi_temp= nullptr;

        if (i_fill_size > 0) {
            pi_temp = new CNode(type);
        } else if (i_fill_size == 0){
            if(Operators::bIsDigit(ss_stream.str())) {
                double d_value = Operators::dGetDigit(ss_stream.str());
                pi_temp = new CNode(type, d_value);
            }else{
                pi_temp = new CNode(type);
                if(type == Operators::Type::variable){
                    pi_temp->vSetName(ss_stream.str()[0]);
                }
            }
        }

        if (!bAddNode(pi_temp)) {
           // str_failure_ += Operators::strTypeToString(type) + " ";
            vAddFailure(type);
            delete pi_temp;
        }
    }


}
double CTree::dCalculationHelper(CNode *pc_node) {
    double d_result;
    if(pc_node== nullptr){
        d_result=0;
    }else {
        /*
        if (pc_node->eGetType() == Operators::NUMBER) {

            d_result = pc_node->dGetValue();

        } else if (pc_node->eGetType() == Operators::COS || pc_node->eGetType() == Operators::SIN) {

            if (pc_node->pcGetLeft() != nullptr) {
                double d_arg = dCalculationHelper(pc_node->pcGetLeft());
                d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg, 0);
            } else {
             //   this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                vAddCalculateFailure(pc_node->eGetType());
                d_result = 0;
            }
        } else {

            if (pc_node->pcGetLeft() != nullptr && pc_node->pcGetRight() != nullptr) {
                double d_arg1 = dCalculationHelper(pc_node->pcGetLeft());
                double d_arg2 = dCalculationHelper(pc_node->pcGetRight());
                d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
            } else if (pc_node->pcGetLeft() != nullptr) {
               // this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                vAddCalculateFailure(pc_node->eGetType());
                double d_arg1 = dCalculationHelper(pc_node->pcGetLeft());
                double d_arg2 = 0;
                d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
            } else if (pc_node->pcGetRight() != nullptr) {
                //this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                vAddCalculateFailure(pc_node->eGetType());
                double d_arg1 = dCalculationHelper(pc_node->pcGetLeft());
                double d_arg2 = 0;
                d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
            } else {
              //  this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                vAddCalculateFailure(pc_node->eGetType());
                d_result = 0;
            }

        }
         */
        int i_arg_counter = Operators::iGetArgCount(pc_node->eGetType());
        switch (i_arg_counter) {
            case 2:
                if (pc_node->pcGetLeft() != nullptr && pc_node->pcGetRight() != nullptr) {
                    double d_arg1 = dCalculationHelper(pc_node->pcGetLeft());
                    double d_arg2 = dCalculationHelper(pc_node->pcGetRight());
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
                    if(pc_node->eGetType()==Operators::Type::DIVIDE && d_arg2==0){
                       // vAddCalculateFailure(pc_node->eGetType());
                       this->str_Calculation_Failure_+=DIVIDE_BY_ZERO;
                       this->str_Calculation_Failure_+=" ";
                    }
                } else if (pc_node->pcGetLeft() != nullptr) {
                    // this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                    vAddCalculateFailure(pc_node->eGetType());
                    double d_arg1 = dCalculationHelper(pc_node->pcGetLeft());
                    double d_arg2 = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
                } else if (pc_node->pcGetRight() != nullptr) {
                    //this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                    vAddCalculateFailure(pc_node->eGetType());
                    double d_arg1 = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    double d_arg2 = dCalculationHelper(pc_node->pcGetRight());
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
                } else {
                    //  this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";

                    vAddCalculateFailure(pc_node->eGetType());

                    double d_arg1 = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    double d_arg2 = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg1, d_arg2);
                }
                break;
            case 1:
                if (pc_node->pcGetLeft() != nullptr) {
                    double d_arg = dCalculationHelper(pc_node->pcGetLeft());
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg, 0);
                } else {
                    //   this->str_failure_ += Operators::strTypeToString(pc_node->eGetType()) + " ";
                    vAddCalculateFailure(pc_node->eGetType());
                    double d_arg = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    d_result = Operators::dExecuteOperation(pc_node->eGetType(), d_arg, 0);
                }
                break;
            case 0:
                if(pc_node->bIsSet()){
                    d_result = pc_node->dGetValue();
                }else{
                    d_result = cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
                    vAddCalculateFailure(pc_node->eGetType());
                }
                break;
        }

    }
    return d_result;
}

bool CTree::bAddNode(CNode *pc_node) {

    bool b_result;
    if(pc_node == nullptr){
     b_result= false;
    }else if(pc_root== nullptr){
        this->pc_root=pc_node;
        b_result= true;
    }else{
        b_result= true;

        CNode* temp =pc_root;
        bool b_loop=true;
        while (b_loop){
            if(temp->i_counter_left>0){
                temp->i_counter_left+= pc_node->iGetFillSize()-1;
                if(temp->pcGetLeft()== nullptr){
                    temp->pcSetLeft(pc_node);
                    b_loop = false;
                }else{
                    temp = temp->pcGetLeft();
                }
            }else if(temp->i_counter_right>0){
                temp->i_counter_right+= pc_node->iGetFillSize()-1;
                if(temp->pcGetRight()== nullptr){
                    temp->pcSetRight(pc_node);
                    b_loop = false;
                }else{
                    temp = temp->pcGetRight();
                }
            }else{
                vAddFailure(temp->eGetType());
                b_loop= false;
                b_result= false;
            }
        }
    }
    return b_result;


}

std::string CTree::
strHelper(CNode* pc_node,bool b_is_completed) {
    std::string str_type = Operators::strTypeToString(pc_node->eGetType());
    Operators::Type e_operator = pc_node->eGetType();


    std::stringstream ss_stream;

    std::string str_substitute;
    if(b_is_completed){
        ss_stream<<cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
        str_substitute = ss_stream.str();
        ss_stream=std::stringstream();
    }else{
        str_substitute.push_back(pc_node->cGetName());
    }

    ss_stream<<"(";

    switch (Operators::iGetArgCount(e_operator)) {
        case 2:
            if(pc_node->pcGetLeft()!= nullptr && pc_node->pcGetRight()!= nullptr){

                //   return strHelper(pc_node->pcGetLeft()) + str_type + strHelper(pc_node->pcGetRight());
                ss_stream<<strHelper(pc_node->pcGetLeft(),b_is_completed)<<str_type<<strHelper(pc_node->pcGetRight(),b_is_completed);
            }else if(pc_node->pcGetLeft()!= nullptr){

                // return strHelper(pc_node->pcGetLeft()) + str_type + "?";
                ss_stream<<strHelper(pc_node->pcGetLeft(),b_is_completed)<<str_type<<str_substitute;
            }else if(pc_node->pcGetRight()!= nullptr){

                // return "?" + str_type + strHelper(pc_node->pcGetRight());
                ss_stream<<str_substitute<<str_type<<strHelper(pc_node->pcGetRight(),b_is_completed);
            }else{
                ss_stream<<str_substitute<<str_type<<str_substitute;
                //  return "?"+str_type+"?";
            }
            break;
        case 1:
            if(pc_node->pcGetLeft()!= nullptr){
                //  return str_type + "(" + strHelper(pc_node->pcGetLeft()) + ")";
                ss_stream<<str_type<<"("<<strHelper(pc_node->pcGetLeft(),b_is_completed)<<")";
            }else{
                // return str_type +"(?)";
                ss_stream<<str_type<<"("<<str_substitute<<")";
            }
            break;
        default:
            if(pc_node->bIsSet() && b_is_completed){
                ss_stream<<pc_node->dGetValue();
            }else{
                if(e_operator == Operators::Type::NUMBER){
                    ss_stream<<pc_node->dGetValue();
                }else {
                    ss_stream << pc_node->cGetName();
                }
            }

            break;
    }

    ss_stream<<")";
    return ss_stream.str();
}

std::string CTree::str_str() {
    return str_str(false);
}
std::string CTree::str_str_autofill() {
    return str_str(true);
}
std::string CTree::str_str(bool b_is_completed) {
    std::string str_result;
    if(pc_root!= nullptr) {
        str_result = strHelper(pc_root, b_is_completed);
    }else{
        str_result ="";
    }
    return str_result;
}

std::string CTree::strFailure() {
    return str_failure_;
}
std::string CTree::strCalculationFailure() {
    return str_Calculation_Failure_;
}
void CTree::vAddFailure(const Operators::Type &type) {
    this->str_failure_+=Operators::strTypeToString(type)+" ";
}
void CTree::vAddCalculateFailure(const Operators::Type &type) {
    this->str_Calculation_Failure_+= Operators::strTypeToString(type) + " ";
}

CTree CTree::operator+(const CTree &other) {
    CTree c_result_tree;
    if(pc_root == nullptr || other.pc_root == nullptr){
        if(pc_root == nullptr && other.pc_root == nullptr){
            c_result_tree =  CTree();
        }else if(this->pc_root == nullptr){
            c_result_tree = other;
        }else{
            c_result_tree = *this;
        }
        return c_result_tree;
    }else {
        if(this->pc_root->iGetFillSize() == 0){
            c_result_tree.pc_root = new CNode(Operators::Type::PLUS);
            vCopyHelper(pc_root,c_result_tree);
            vCopyHelper(other.pc_root,c_result_tree);
        }else{
            vCopyHelper(pc_root, c_result_tree);
            vCopyHelper(other.pc_root, c_result_tree);
        }
    }
    return c_result_tree;
}
CTree CTree::operator+(CTree&& other){
    CTree c_result_tree = std::move(other);
    if(pc_root != nullptr){
        if(c_result_tree.pc_root->iGetFillSize() == 0){
            CNode* pc_root_old = c_result_tree.pc_root;
            c_result_tree.pc_root = new CNode(Operators::Type::PLUS);
            c_result_tree.pc_root->pcSetLeft(pc_root_old);
            c_result_tree.pc_root->i_counter_left=0;


            vCopyHelper(pc_root,c_result_tree);
        }else{
            vCopyHelper(pc_root, c_result_tree);
        }
    }
    return c_result_tree;
    /*
    CTree c_temp = std::move(other);
    return *this + c_temp;
    */
}

void CTree::vCopyHelper(CNode *pc_node, CTree &c_Tree_copy) { //kopiuje kazdy lisc po kolei
    if(pc_node != nullptr) {
        CNode *pc_copy = new CNode(*pc_node);
        if (!c_Tree_copy.bAddNode(pc_copy)) {
            c_Tree_copy.vAddFailure(pc_copy->eGetType());
            delete pc_copy;
        } else {
            if (pc_node->pcGetLeft() != nullptr)vCopyHelper(pc_node->pcGetLeft(), c_Tree_copy);
            if (pc_node->pcGetRight() != nullptr)vCopyHelper(pc_node->pcGetRight(), c_Tree_copy);
        }
    }
}


CTree::CTree() {
    vFirstInit();
}

void CTree::operator=(const CTree &other) {
    delete this->pc_root;
    vFirstInit();
    vCopyHelper(other.pc_root,*this);

}
CTree& CTree::operator=(CTree &&cOther) noexcept{

    delete this->pc_root;

    this->pc_root = cOther.pc_root;
    this->str_failure_ = cOther.str_failure_;
    this->str_Calculation_Failure_ = cOther.str_Calculation_Failure_;
    cOther.pc_root = nullptr;
    cOther.str_failure_=std::string();
    cOther.str_Calculation_Failure_=std::string();

    return *this;
}

bool CTree::bSetVariable(char c_name,double d_value) {
    bool b_result;
    if(pc_root!= nullptr){
        b_result = bSetHelper(pc_root,c_name,d_value);
    }else{
        b_result = false;
    }
    return b_result;
}

int CTree::iGetLeaves() {
    int result = 0;
    if(pc_root!= nullptr) {
        result = iGetLeavesHelpe(pc_root);
    }
    return result;
}

bool CTree::bSetHelper(CNode *pc_node,char c_name,double d_value) {
    bool b_result= false;

    if(pc_node->eGetType()==Operators::Type::variable && pc_node->cGetName() == c_name) {
        pc_node->vSet(d_value);
        b_result = true;
    }

    if(pc_node->pcGetLeft()!= nullptr){
        bool b_temp= bSetHelper(pc_node->pcGetLeft(),c_name,d_value);
        b_result = b_temp||b_result;
    }
    if(pc_node->pcGetRight()!= nullptr){
        bool b_temp= bSetHelper(pc_node->pcGetRight(),c_name,d_value);
        b_result = b_temp||b_result;
    }

    return b_result;
}

void CTree::vCheckFailure(CNode* pc_node) {
    if(pc_node!= nullptr){
        bool b_is_failed= false;
        if(pc_node->i_counter_left>0){
            if(pc_node->pcGetLeft()!= nullptr){
                vCheckFailure(pc_node->pcGetLeft());
            }else{
                b_is_failed= true;
            }
        }
        if(pc_node->i_counter_right>0){
            if(pc_node->pcGetRight()!= nullptr){
                vCheckFailure(pc_node->pcGetRight());
            }else{
                b_is_failed= true;
            }
        }
        if(b_is_failed){
            vAddFailure(pc_node->eGetType());
        }
    }
}

int CTree::iGetLeavesHelpe(CNode *pc_node) {
    int result=0;
    if(pc_node!= nullptr) {
        int i_arg_count = Operators::iGetArgCount(pc_node->eGetType());
        switch (i_arg_count) {
            case 2:
                if(pc_node->pcGetLeft()!= nullptr) {
                    result += iGetLeavesHelpe(pc_node->pcGetLeft());
                }
                if(pc_node->pcGetRight()!= nullptr) {
                    result += iGetLeavesHelpe(pc_node->pcGetRight());
                }
                break;
            case 1:
                if(pc_node->pcGetLeft()!= nullptr) {
                    result += iGetLeavesHelpe(pc_node->pcGetLeft());
                }
                break;
            default:
                result= 1;
        }

    }
    return result;
}
































