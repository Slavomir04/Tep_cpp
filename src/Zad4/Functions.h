//
// Created by Sławomir on 23.11.2024.
//

#ifndef PROGRAMY_C___TEP_FUNCTIONS_H
#define PROGRAMY_C___TEP_FUNCTIONS_H
#include "CResult.h"
#include "CError.h"
#include "../Zad3/CTree.h"
#include "../Zad3/Operators.h"
#include "ConstansZad4.h"
#include <strstream>





std::vector<std::string> vecParseStrings(std::string str_line);
CResult<double,CError> rDivide(double d_up, double d_down);
CResult<CTree,CError> rGetTree(std::string str_equasion);
CResult<int*,int> rTest(int i_x,int i_y);


#endif //PROGRAMY_C___TEP_FUNCTIONS_H
