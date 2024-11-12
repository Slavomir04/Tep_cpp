//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CTREE_H
#define PROGRAMY_C___TEP_CTREE_H

#include "CNode.h"
#include "Operators.h"
#include "Constans.h"
#include <sstream>
class CTree {
public:
    CTree(std::string &str_equation);
    CTree(const CTree &other);
    ~CTree();

    double dCalculate();
    CTree operator+(const CTree& other);
    std::string str_str();
    std::string strFailure();
private:

    CNode* pc_root;
    std::string str_failure_;

    CTree();
    void vCopyHelper(CNode* pc_node, CTree &c_Tree_copy);
    bool bAddNode(CNode *pc_node);
    bool bAddHelper(CNode *pc_node,CNode *pc_destination);
    void vFirstInit();
    void vMakeTree(std::string &str_onp);
    double dCalculateHelper(CNode *pc_node);
    std::string strHelper(CNode* pc_node);
    void vAddFailure(const Operators::Type &type);

};


#endif //PROGRAMY_C___TEP_CTREE_H
