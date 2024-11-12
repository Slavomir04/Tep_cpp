//
// Created by Sławomir on 12.11.2024.
//

#ifndef PROGRAMY_C___TEP_CLI_H
#define PROGRAMY_C___TEP_CLI_H
#include <vector>
#include "CTree.h"
class CLI {
public:
    void vStart();
private:
    void vExecuteCommand(const std::string &command);
    std::vector<std::string> vecParseLine(const std::string &command,char c_shift);
    std::vector<CTree> vec_tree;
};


#endif //PROGRAMY_C___TEP_CLI_H
