#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad3/Operators.h"
#include "src/Zad3/CTree.h"
#include "src/Zad3/RNPgenerator.h"
#include <algorithm>
void CLI(){
    while (true){
        string line;
        printf("pisz:");
        cin>>line;
        if(line=="exit")break;
        printf("%s\n", strRPN2(line).c_str());
    }
}
void showTest(string s){
    printf("\n---------------------------------\n");
    CTree tree(s);
    CTree copy(tree);
    printf("string: %s\n",s.c_str());
    printf("str_str: %s\n",tree.str_str().c_str());
    printf("calculated: %.2f\n",tree.dCalculate());
    printf("failure: %s\n",tree.strFailure().c_str());

    printf("copy\n");
    printf("string: %s\n",s.c_str());
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
    printf("\n---------------------------------\n");
}

using namespace std;
int main() {
    const int size=15;
    string expectedResults[size] = {
            "3 4 +",
            "2 3 * 4 +",
            "5 2 3 * +",
            "1 2 + 4 *",
            "3 4 2 * 1 5 - / +",
            "2 3 + 7 4 - *",
            "7 8 3 2 + * +",
            "5 6 * 7 8 9 + * -",
            "3 5 + 2 * 4 /",
            "10 2 6 * + 8 4 / -",
            "15 3 - 4 2 * 1 1 + / +",
            "4 5 2 * 3 + +",
            "1 2 3 * + 4 2 / -",
            "3 2 4 + * 5 -",
            "8 4 2 - 6 3 / * +"
    };
    //for(int i=0; i<size; i++)showTest(expectedResults[i]);
  //  showTest(expectedResults[4]);
    string st1 = "+ 1";
    string st2 = "+ 2";
  CTree t1(st1);
  CTree t2(st2);
    showTree(t1);
    showTree(t2);
//  CTree t3 = t1+t2;
 // showTree(t3);
}


