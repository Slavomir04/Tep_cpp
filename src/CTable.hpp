//
// Created by slawe on 06.10.2024.
//

#ifndef PROGRAMY_C___TEP_CTABLE_HPP
#define PROGRAMY_C___TEP_CTABLE_HPP
#include <iostream>

class CTable {

public:
    CTable(){

        std::string str_Default_Name = "noname";
        i_Table_Len = 0;
        vSetName(str_Default_Name);
    }
    CTable(CTable &pc_Other){

        std::string str_Copy_Tag = "_copy";
        vSetName(pc_Other.str_Name+str_Copy_Tag);
        if(bSetNewSize(pc_Other.i_Table_Len)){
            for(int i=0; i<i_Table_Len; i++){
                pi_Table[i]=pc_Other.pi_Table[i];
            }
        }
        std::cout<<"kopiuj:"<<str_Name<<'\n';
    }
    CTable(std::string str_Name,int i_Table_Len){

        vSetName(str_Name);
        bSetNewSize(i_Table_Len);
    }
    ~CTable(){

        if(i_Table_Len!=0){
            delete[] pi_Table;
        }
    }
    void vSetName(std::string str_Name){
        this->str_Name=str_Name;
    }
    bool bSetNewSize(int i_TableSize){
        if(i_TableSize<=0){
            return false;
        } else{
            this->i_Table_Len = i_TableSize;
            this->pi_Table = new int[i_TableSize];
            return true;
        }
    }

    CTable* pcClone(){
        return new CTable(*this);
    }

    void test(){
        std::cout<<str_Name<<" ";
        for(int i=0; i<i_Table_Len; i++){
            std::cout<<pi_Table[i]<<' ';
        }
        std::cout<<'\n';
    }

private:
    std::string str_Name;
    int i_Table_Len;
    int* pi_Table;
};


#endif //PROGRAMY_C___TEP_CTABLE_HPP
