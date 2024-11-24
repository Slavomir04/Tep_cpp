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
class Saver {
public:
    Saver(std::string &str_path);
    template<typename T>
    bool bSave(CResult<T,CError> &pc_CResult);
private:
   std::string str_path;
};
Saver::Saver(std::string &str_path) : str_path(str_path){
}

template<typename T>
bool Saver::bSave(CResult<T, CError> &pc_CResult) {
    bool b_result = std::filesystem::exists(str_path);
    if(b_result) {
        std::ofstream ofs_file(str_path, std::ios::app);
        b_result = ofs_file.is_open();
        if (ofs_file) {
            std::vector<CError *> vec = pc_CResult.vGetErrors();
            if (!vec.empty()) {
                ofs_file<<"\n";
                for (int i = 0; i < vec.size(); i++) {
                    ofs_file << vec[i]->strGetError() << '\n';
                }
            }
        }
        ofs_file.close();
    }
    return b_result;
}

#endif //PROGRAMY_C___TEP_SAVER_H
