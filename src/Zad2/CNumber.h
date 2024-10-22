//
// Created by slawe on 22.10.2024.
//
#include "Constans.h"
#include<string>
#include<sstream>
#ifndef CNUMBER_H
#define CNUMBER_H



class CNumber {

public:
    CNumber();
    CNumber(CNumber &pc_value_to_copy);
    ~CNumber();

    void vSet(int i_new_value);
    void operator=(const CNumber &pc_new_value);
    const CNumber operator+(CNumber &pc_new_value);
    const CNumber operator-(CNumber &pc_new_value);
    const CNumber operator*(CNumber &pc_new_value);
    const CNumber operator/(CNumber &pc_new_value);
    void operator=(int i_new_value);
    const CNumber operator+(int i_new_value);
    const CNumber operator-(int i_new_value);
    const CNumber operator*(int i_new_value);
    const CNumber operator/(int i_new_value);

    std::string str_str();
private:
    void vFirstInit();
    int* pi_number;
    int i_length;
    bool b_is_neg;

};



#endif //CNUMBER_H
