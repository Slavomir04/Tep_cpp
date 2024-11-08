//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CNODE_H
#define PROGRAMY_C___TEP_CNODE_H
#include "Operators.h"

class CNode {
public:
    CNode(Operators::Type e_operator);
    CNode(Operators::Type e_operator,double d_value);
    ~CNode();
    void pcSetLeft(CNode* pcNewLeft);
    void pcSetRight(CNode* pcNewRight);
    CNode *pcGetLeft();
    CNode *pcGetRight();
    double dGetValue();

    int i_counter_left;
    int i_counter_right;

    private:
    void vFirstInit();
    double d_value;
    Operators::Type e_operator;
    CNode *pc_next_left;
    CNode *pc_next_right;
};


#endif //PROGRAMY_C___TEP_CNODE_H
