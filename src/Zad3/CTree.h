//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CTREE_H
#define PROGRAMY_C___TEP_CTREE_H

#include "CNode.h"
#include "Operators.h"

class CTree {
public:
    CTree(std::string str_equation);
    ~CTree();

    double dCalculate();
    CTree* operator+(const CTree& other);

private:
    CTree* pc_Copy();
    void vFirstInit();
    void vMakeTree();
    std::string strToONP(std::string &str_equation);
    CNode* pc_root;

};


#endif //PROGRAMY_C___TEP_CTREE_H
