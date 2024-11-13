#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad3/Operators.h"
#include "src/Zad3/CTree.h"
#include "src/Zad3/CLIZad3.h"
#include <algorithm>
using namespace std;
void showTest(string s){
    printf("\n---------------------------------\n");
    CTree tree(s);
    CTree copy(tree);
    printf("string: %s\n\n\n",s.c_str());
    printf("str_str: %s\n",tree.str_str().c_str());
    printf("calculated: %.2f\n",tree.dCalculate());
    printf("failure: %s\n",tree.strFailure().c_str());

    printf("\ncopy:\n");
    printf("str_str: %s\n",copy.str_str().c_str());
    printf("calculated: %.2f\n",copy.dCalculate());
    printf("failure: %s\n",copy.strFailure().c_str());
    printf("\n---------------------------------\n");
}
void showTree(CTree &pc_tree){
    printf("\n---------------------------------\n");
    printf("str_str: %s\n",pc_tree.str_str().c_str());
    printf("str_str completed: %s\n",pc_tree.str_str(true).c_str());
    printf("calculated: %.2f\n",pc_tree.dCalculate());
    printf("failure: %s\n",pc_tree.strFailure().c_str());
    printf("Calculationfailure: %s\n",pc_tree.strCalculationFailure().c_str());
    printf("\n---------------------------------\n");
}


int main() {
    CLIZad3 cli;
    cli.vStart();
  /*
  string s1="* 1 5";
  string s2="/ 0.64";
  CTree t1(s1);
  CTree t2(s2);
    showTree(t1);
    showTree(t2);

    CTree t3 = t2+t1;
    showTree(t3);
    */


}


