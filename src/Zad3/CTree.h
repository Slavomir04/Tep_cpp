//
// Created by Sławomir on 06.11.2024.
//

#ifndef PROGRAMY_C___TEP_CTREE_H
#define PROGRAMY_C___TEP_CTREE_H

#include "CNode.h"
#include "Operators.h"
#include "ConstansZad3.h"
#include <sstream>
#define DIVIDE_BY_ZERO "/0"
class CNode;
class CTree {
public:
    CTree(const std::string &str_equation);
    CTree();
    CTree(const CTree &cOther);
    CTree(CTree &&cOther) noexcept;
    ~CTree();

    double dCalculate();
    CTree operator+(const CTree& other);
    CTree operator+(CTree&& other);

    void operator=(const CTree& other);
    CTree& operator=(CTree&& cOther) noexcept;
    std::string str_str();
    std::string str_str_autofill();
    std::string str_str(bool b_is_completed);
    std::string strFailure();
    std::string strCalculationFailure();
    bool bSetVariable(char c_name,double d_value);
    int iGetLeaves();
private:

    CNode* pc_root;
    std::string str_failure_;
    std::string str_Calculation_Failure_;

    void vCopyHelper(CNode* pc_node, CTree &c_Tree_copy);
    bool bAddNode(CNode *pc_node);
    void vFirstInit();
    void vMakeTree(const std::string &str_equasion);
    double dCalculationHelper(CNode *pc_node);
    std::string strHelper(CNode* pc_node,bool b_is_completed);
    void vAddFailure(const Operators::Type &type);
    void vAddCalculateFailure(const Operators::Type &type);
    bool bSetHelper(CNode* pc_node,char c_name,double d_value);
    void vCheckFailure(CNode* pc_node);
    int iGetLeavesHelpe(CNode* pc_node);


};


#endif //PROGRAMY_C___TEP_CTREE_H
