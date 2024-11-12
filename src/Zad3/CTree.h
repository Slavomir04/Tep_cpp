//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CTREE_H
#define PROGRAMY_C___TEP_CTREE_H

#include "CNode.h"
#include "Operators.h"
#include "ConstansZad3.h"
#include <sstream>
class CTree {
public:
    CTree(std::string &str_equation);
    CTree(const CTree &other);
    ~CTree();

    double dCalculate();
    CTree operator+(const CTree& other);
    void operator=(const CTree& other);
    std::string str_str();
    std::string strFailure();
    std::string strCalculationFailure();
    bool bSetVariable(char c_name,double d_value);
private:

    CNode* pc_root;
    std::string str_failure_;
    std::string str_Calculation_Failure_;
    CTree();
    void vCopyHelper(CNode* pc_node, CTree &c_Tree_copy);
    bool bAddNode(CNode *pc_node);
    void vFirstInit();
    void vMakeTree(std::string &str_equasion);
    double dCalculationHelper(CNode *pc_node);
    std::string strHelper(CNode* pc_node);
    void vAddFailure(const Operators::Type &type);
    void vAddCalculateFailure(const Operators::Type &type);
    bool bSetHelper(CNode* pc_node,char c_name,double d_value);
};


#endif //PROGRAMY_C___TEP_CTREE_H
