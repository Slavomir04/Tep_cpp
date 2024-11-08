//
// Created by Sławomir on 06.11.2024.
//

#include "CNode.h"

CNode::CNode(Operators::Type e_operator) {
    vFirstInit();
    this->e_operator=e_operator;
}

CNode::CNode(Operators::Type e_operator,double d_value) {
    vFirstInit();
    this->e_operator = e_operator;
    this->d_value = d_value;
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
        this->pc_next_left = pcNewRight;
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


void CNode::vFirstInit() {
    this->e_operator = Operators::UNKNOWN;
    this->d_value=0;
    this->i_counter_left=0;
    this->i_counter_right=0;
    this->pc_next_left=nullptr;
    this->pc_next_right=nullptr;
}
