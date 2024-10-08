#include <iostream>
#include "src/CTable.hpp"
#include "src/Tool.hpp"
void v_alloc_table_fill_34(int iSize){

    const int i_FillValue=34;
    const char c_shift=',';
    if(iSize<=0){

    }else{
        int* pi_pointer = new int[iSize];
        for(int i=0; i<iSize; i++){
            pi_pointer[i]=i_FillValue;
        }

        for(int i=0; i<iSize; i++){
            std::cout<<pi_pointer[i]<<c_shift;
        }
        std::cout<<"\n";

        delete[] pi_pointer;
    }
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
    if(iSizeX<=0 || iSizeY<=0){
        return false;
    }else{
        *piTable = new int*[iSizeX];
        for(int i=0; i<iSizeX; i++){
            (*piTable)[i]=new int[iSizeY];
        }
        return true;
    }
}

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX,int iSizeY) {
    if(iSizeX<=0 || iSizeY<=0){
        return false;
    }else{
        for(int i=0; i<iSizeX; i++){
            delete[] (*piTable)[i];
        }
        delete[] *piTable;
        return true;
    }
}
void test(){
    CTable c;
}


int main() {
    /*
    int **p;
    int x=2;
    int y=6;
    std::cout<<"alloc 2dim:"<<b_alloc_table_2_dim(&p,x,y)<<'\n';
    b_fill_table(&p,x,y,5);
    Tool::v_show_table(&p,x,y);
    std::cout<<"dealloc 2dim:"<<b_alloc_table_2_dim(&p,x,y)<<'\n';
     */
    int x=5;
    int y=5;
    std::string** pStr_array = new std::string*[x];
    for(int i=0; i<x; i++)pStr_array[i]=new std::string[y];

    Tool::b_fill_table<std::string>(&pStr_array,x,y,"dupa");
    Tool::v_show_table<std::string>(&pStr_array,x,y);

    for(int i=0; i<x; i++)delete[] pStr_array[i];
    delete[] pStr_array;
    return 0;
}
