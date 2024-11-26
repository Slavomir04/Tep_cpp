//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CNODE_H
#define PROGRAMY_C___TEP_CNODE_H
#include "Operators.h"
#include "ConstansZad3.h"
#include "CTree.h"
class CTree;
class CNode {
public:
    CNode(const CNode &pc_other);
    CNode(Operators::Type e_operator);
    CNode(Operators::Type e_operator,double d_value);
    ~CNode();
    void pcSetLeft(CNode* pcNewLeft);
    void pcSetRight(CNode* pcNewRight);
    CNode *pcGetLeft();
    CNode *pcGetRight();
    double dGetValue();
    Operators::Type eGetType();

    int iGetFillSize();
    void vSet(double d_value);
    bool bIsSet();
    char cGetName();
    void vSetName(char c_name);
    private:
    int i_counter_left;
    int i_counter_right;
    char c_name;
    bool b_is_set;
    double d_value;
    Operators::Type e_operator;
    CNode *pc_next_left;
    CNode *pc_next_right;

    void vFirstInit();
    void vSetDefaultFill();

    friend class CTree;
};


#endif //PROGRAMY_C___TEP_CNODE_H
