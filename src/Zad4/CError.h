//
// Created by Sławomir on 22.11.2024.
//

#ifndef PROGRAMY_C___TEP_CERROR_H
#define PROGRAMY_C___TEP_CERROR_H
#include <string>

class CError {
public:
   CError(std::string str_Error);
    CError(CError &c_CError_original);
    std::string strGetError();
private:
    const std::string str_Error;
};


#endif //PROGRAMY_C___TEP_CERROR_H
