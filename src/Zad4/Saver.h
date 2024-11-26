//
// Created by Sławomir on 22.11.2024.
//

#ifndef PROGRAMY_C___TEP_SAVER_H
#define PROGRAMY_C___TEP_SAVER_H
#include <iostream>
#include <fstream>
#include "CResult.h"
#include "CError.h"
#include <filesystem>
#include <ctime>




std::string str_getTime() {
    std::time_t time_now = std::time(nullptr);
    std::tm* pc_local_time = std::localtime(&time_now);
    char c_buffer[100];
    std::strftime(c_buffer, sizeof(c_buffer), "%Y-%m-%d %H:%M:%S", pc_local_time);
    return std::string(c_buffer);
}



template<typename T>
bool bSave(CResult<T, CError> &pc_CResult,const std::string &str_path) {
    bool b_result = std::filesystem::exists(str_path);
    if(b_result) {
        std::fstream f_printer(str_path,std::ios::app);
        b_result = f_printer.is_open();
        if (f_printer) {
            std::vector<CError *> vec = pc_CResult.vGetErrors();
            if (!vec.empty()) {
                f_printer << "\n"<<str_getTime()<<"\n";
                for (int i = 0; i < vec.size(); i++) {
                    f_printer << vec[i]->strGetError() << '\n';
                }
            }
        }
        f_printer.close();
    }
    return b_result;
}
template<>
bool bSave(CResult<CTree, CError> &pc_CResult,const std::string &str_path) {
    bool b_result = std::filesystem::exists(str_path);
    if(b_result) {
        std::fstream f_printer(str_path,std::ios::app);
        b_result = f_printer.is_open();
        if (f_printer) {
            f_printer << "\n" << str_getTime() << "\n";
            if(pc_CResult.bIsSuccess()){
                f_printer<<pc_CResult.cGetValue().str_str()<<'\n';
            }
            else {
                std::vector<CError *> vec = pc_CResult.vGetErrors();
                if (!vec.empty()) {
                    for (int i = 0; i < vec.size(); i++) {
                        f_printer << vec[i]->strGetError() << '\n';
                    }
                }
            }
        }
        f_printer.close();
    }
    return b_result;
}



#endif //PROGRAMY_C___TEP_SAVER_H
