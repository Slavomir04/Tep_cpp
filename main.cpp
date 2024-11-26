#include <iostream>
#include "src/Zad3/CTree.h"

#include "src/Zad4/CResult.h"
#include "src/Zad4/Functions.h"
#include "src/Zad4/Saver.h"
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

void showCResult(CResult<CTree,CError> cResult){
    cout<<"CResult:\n";
    if(cResult.bIsSuccess()){
        cout<<cResult.cGetValue().str_str()<<'\n';
    }else{
        vector<CError*> vec = cResult.vGetErrors();
        for(auto& error : vec)cout<<error->strGetError()<<'\n';
    }
    cout<<'\n';
}
void showVoid(CResult<void,CError> cResult){
    cout<<"CResult:\n";
    if(cResult.bIsSuccess()){
        cout<<"void"<<'\n';
    }else{
        vector<CError*> vec = cResult.vGetErrors();
        for(auto& error : vec)cout<<error->strGetError()<<'\n';
    }
    cout<<'\n';
}



int main() {



    string path = "../src/Zad4/file123456789.txt"; //relative path jest w cmake-build-debug

    CResult<CTree,CError> c_result = rGetTree("+ + 1 2 3  ");
    CResult<double,CError> c_divide = rDivide(5,0);
    if(!bSave<CTree>(c_result,path))cerr<<"nie dziala!";
    if(!bSave<double>(c_divide,path))cerr<<"nie dziala!";






}


