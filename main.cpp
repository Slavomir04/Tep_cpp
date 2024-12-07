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


int main() {



    string path = "../src/Zad4/file123456789.txt"; //relative path jest w cmake-build-debug

    /*
    CResult<void,CError> c_result_void(new CError("void"));
    CResult<CTree,CError> c_result = rGetTree("/ 1 0");
    CResult<double,CError> c_divide = rDivide(5,0);

    if(!bSave<void>(c_result_void,path))cerr<<"nie dziala!";
    if(!bSave<CTree>(c_result,path))cerr<<"nie dziala!";
    if(!bSave<double>(c_divide,path))cerr<<"nie dziala!";
    */

    CResult<double,CError> c_divide = rDivide(5,1);
    CResult<double,CError> c_divide_copy = c_divide;
    showCResult(c_divide);
    showCResult(c_divide_copy);
    CResult<int*,int> c_test = rTest(1,-1);
   CResult<int*,int> c_test_copy = c_test;
   showModyfikacja(c_test);
    showModyfikacja(c_test_copy);

   // if(!bSave(c_test,path))cerr<<"nie dziala!";







}


