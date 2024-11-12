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
    this->e_operator = e_operator;
    this->d_value = d_value;
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
    this->d_value=0;
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

CNode::CNode(const CNode &pc_other) {
    vFirstInit();
    this->e_operator = pc_other.e_operator;
    this->d_value = pc_other.d_value;
    vSetDefaultFill();
}

void CNode::vSetDefaultFill() {
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
}


