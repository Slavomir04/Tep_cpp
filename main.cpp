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
        printf("\n\n");
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




using namespace std;
int main() {

    CMySmartPointer<int> c_ptr(new int(12));
    cout<<*c_ptr<<endl;
    c_ptr = 30;
    cout<<*c_ptr<<endl;
    int i_val=20;
    c_ptr=i_val;
    cout<<*c_ptr<<endl;
    CMySmartPointer<int> c_copy(c_ptr);
    c_ptr=21;
    cout<<*c_ptr<<endl;
    c_ptr=i_val;
    cout<<*c_ptr<<endl;

    CTree t1("+ 1 2");
    CTree t2("+ 1 3");
    CTree t3 = t1 + std::move(t2);


    showTree(&t1);
    showTree(&t2);
    showTree(&t3);

}


