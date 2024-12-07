#include <iostream>
#include "src/Zad3/CTree.h"

#include "src/Zad4/CResult.h"
#include "src/Zad4/Functions.h"
#include "src/Zad4/Saver.h"
#include "src/Zad5/CMySmartPointer.h"
#include <utility>
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
template<typename T>
void showCResult(CResult<T,CError> &cResult){
    cout<<"CResult:\n";
    if(cResult.bIsSuccess()){
            cout<<cResult.cGetValue()<<'\n';

    }else{
        vector<CError*> vec = cResult.vGetErrors();
        for(auto& error : vec)cout<<error->strGetError()<<'\n';
    }
    cout<<'\n';
}
template<>
void showCResult(CResult<CTree,CError> &cResult){
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

void showModyfikacja(CResult<int*,int> cResult) {
    cout<<"CResult:\n";
    if(cResult.bIsSuccess()){
        cout<<"good: ";
        cout<<*cResult.cGetValue()<<'\n';
    }else{
        cout<<"fails:\n";
        vector<int*> vec = cResult.vGetErrors();
        for(auto& error : vec)cout<<*error<<'\n';
    }
    cout<<'\n';
}

void test_mypointer(CMySmartPointer<CTree> &pointer){
    CMySmartPointer<CTree> pointer_2 = pointer;
    printf("pointer z funkcji:%s\n",(*pointer_2).str_str().c_str());
}

int main() {





}


