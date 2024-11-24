#include <iostream>
#include "src/Zad3/CTree.h"
#include "src/Zad4/Saver.h"
#include "src/Zad4/CResult.h"
#include "src/Zad4/Functions.h"
#include <filesystem>
using namespace std;

void showTree(CTree* tree){
    if(tree!= nullptr) {
        printf("str_str: %s\n", tree->str_str().c_str());
        printf("calculate: %.2f\n", tree->dCalculate());
        printf("failure: %s\n", tree->strFailure().c_str());
        printf("calculation failure: %s\n", tree->strCalculationFailure().c_str());
    }
}

int main() {



    string path = "../src/Zad4/file123456789.txt"; //relative path jest w cmake-build-debug
    Saver saver(path);
    CResult<CTree,CError> c_result = rGetTree("/ * + + *");
    if(!saver.bSave(c_result))cerr<<"nie dziala!";


}


