//
// Created by Sławomir on 22.11.2024.
//

#include "CError.h"

CError::CError(std::string str_Error): str_Error(str_Error) {}
CError::CError(CError &c_CError_original) : str_Error(std::string (c_CError_original.str_Error)){}
std::string CError::strGetError() {
    return str_Error;
}


