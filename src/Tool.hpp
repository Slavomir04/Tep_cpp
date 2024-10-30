//
// Created by slawe on 08.10.2024.
//

#ifndef PROGRAMY_C___TEP_TOOL_HPP
#define PROGRAMY_C___TEP_TOOL_HPP
#include <iostream>

class Tool {
public:
    template<class T>
    static void v_show_table(T*** pTemplate, int iSizeX, int iSizeY){
        if(iSizeX<=0 || iSizeY<=0 || pTemplate == nullptr){
            const std::string str_fail=" jest bledny!\n";
            const std::string str_correct="";
            std::cout
                    <<((iSizeX<=0) ? ("iSizeX"+str_fail) : str_correct)
                    <<((iSizeY<=0) ? ("iSizeY"+str_fail) : str_correct)
                    <<((pTemplate == nullptr) ? ("pTemplate" + str_fail) : str_correct);
        }else{
            for(int i=0; i<iSizeX; i++){
                for(int y=0; y<iSizeY; y++){
                    std::cout << (*pTemplate)[i][y] << ' ';
                }
                std::cout<<'\n';
            }
        }
    }

    template<class T>
    static bool b_fill_table(T*** pTemplate, int iSizeX, int iSizeY, T T_value){
        if(iSizeX<=0 || iSizeY<=0){
            return false;
        }else{
            for(int i=0; i<iSizeX; i++){
                for(int y=0; y<iSizeY; y++){
                    (*pTemplate)[i][y]=T_value;
                }
            }
            return true;
        }
    }

    template<class T>
    static void v_show_array(T* &pc_Template,int i_size){
        for(int i=0; i<i_size; i++){
            std::cout<<pc_Template[i]<<" ";
        }
        std::cout<<'\n';
    }


};


#endif //PROGRAMY_C___TEP_TOOL_HPP
