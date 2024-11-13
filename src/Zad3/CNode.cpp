//
// Created by Sławomir on 06.11.2024.
//

#include "CNode.h"

CNode::CNode(Operators::Type e_operator) {
    vFirstInit();
    this->e_operator=e_operator;
    vSetDefaultFill();
}

CNode::CNode(Operators::Type e_operator,double d_value) {
    vFirstInit();
    this->b_is_set= true;
    this->e_operator = e_operator;
    this->d_value = d_value;
    vSetDefaultFill();
}
CNode::CNode(const CNode &pc_other) {
    vFirstInit();
    this->e_operator = pc_other.e_operator;
    this->d_value = pc_other.d_value;
    this->c_name=pc_other.c_name;
    this->b_is_set=pc_other.b_is_set;
    vSetDefaultFill();
}

CNode::~CNode() {
    delete pc_next_left;
    delete pc_next_right;
}

void CNode::pcSetLeft(CNode *pcNewLeft) {
    if(pcNewLeft != nullptr) {
        this->pc_next_left = pcNewLeft;
    }
}

void CNode::pcSetRight(CNode *pcNewRight) {
    if(pcNewRight != nullptr) {
        this->pc_next_right = pcNewRight;
    }
}

CNode * CNode::pcGetLeft() {
    return this->pc_next_left;
}

CNode * CNode::pcGetRight() {
    return this->pc_next_right;
}

double CNode::dGetValue() {
    return d_value;
}
Operators::Type CNode::eGetType() {
    return this->e_operator;
}

void CNode::vFirstInit() {
    this->e_operator = Operators::UNKNOWN;
    this->b_is_set= false;
    this->c_name='?';
    this->d_value=cstZad3::d_DEFAULT_VALUE_OF_VARIABLE;
    this->i_counter_left=0;
    this->i_counter_right=0;
    this->pc_next_left=nullptr;
    this->pc_next_right=nullptr;
}

int CNode::iGetFillSize() {
    /*
    int i_result;
    if(this->e_operator==Operators::MINUS || this->e_operator==Operators::PLUS || this->e_operator==Operators::MULL || this->e_operator==Operators::DIVIDE){
        i_result=2;
    }else if(this->e_operator==Operators::SIN || this->e_operator==Operators::COS){
        i_result=1;
    }else{
        i_result=0;
    }
    return i_result;
     */
    return i_counter_left+i_counter_right;
}



void CNode::vSetDefaultFill() {
    /*
    if(e_operator == Operators::PLUS||e_operator == Operators::MINUS||e_operator == Operators::MULL||e_operator == Operators::DIVIDE){
        this->i_counter_left=1;
        this->i_counter_right=1;
    }else if(e_operator == Operators::SIN||e_operator == Operators::COS){
        this->i_counter_left=1;
        this->i_counter_right=0;
    }else{
        this->i_counter_left=0;
        this->i_counter_right=0;
    }
     */
    int i_arg_count = Operators::iGetArgCount(e_operator);
    switch (i_arg_count) {
        case 2:
            this->i_counter_left=1;
            this->i_counter_right=1;
            break;
        case 1:
            this->i_counter_left=1;
            this->i_counter_right=0;
            break;
        default:
            this->i_counter_left=0;
            this->i_counter_right=0;
            break;
    }
}

bool CNode::bIsSet() {
    return b_is_set;
}

void CNode::vSet(double d_value) {
    this->d_value=d_value;
    this->b_is_set= true;
}

char CNode::cGetName() {
    return c_name;
}

void CNode::vSetName(char c_name) {
    this->c_name=c_name;
}


