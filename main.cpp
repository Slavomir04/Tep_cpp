#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad3/Operators.h"
#include "src/Zad3/CTree.h"

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
    printf("calculated: %.2f\n",pc_tree.dCalculate());
    printf("failure: %s\n",pc_tree.strFailure().c_str());
    printf("Calculationfailure: %s\n",pc_tree.strCalculationFailure().c_str());
    printf("\n---------------------------------\n");
}


int main() {
    string s1 = "a";
    string s2 = "b";
    string s3 = "/";
    CTree t1(s1);
    CTree t2(s2);
    CTree t3(s3);

   cout<< t1.bSetVariable('a',0)<<endl;
    cout<< t2.bSetVariable('b',0)<<endl;
    showTree(t1);
    showTree(t2);
    showTree(t3);

    CTree test = t3+t2+t1;
    showTree(test);


}


