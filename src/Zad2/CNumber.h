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
    CNumber(int i_value);
    CNumber(CNumber &pc_value_to_copy);
    ~CNumber();

    void vSet(int i_new_value);
    void operator=(const CNumber &pc_new_value);
    CNumber operator+(const CNumber &pc_new_value);
    CNumber operator-(const CNumber &pc_new_value);
    CNumber operator*(const CNumber &pc_new_value);
    CNumber operator/(const CNumber &pc_new_value);
    void operator=(int i_new_value);

    CNumber operator+(int i_new_value);
    CNumber operator-(int i_new_value);
    CNumber operator*(int i_new_value);
    CNumber operator/(int i_new_value);

    std::string str_str();



private:
    CNumber addTwoNumbers(const CNumber &pc_new_value);
    CNumber subtractTwoNumbers(const CNumber &pc_new_value);
    CNumber multiplyTwoNumbers(const CNumber &pc_new_value);
    void vAddArrays(int* &pi_result,int i_size_result,int* &pi_other,int i_length_other);
    void vTrim();
    void v_Copy(const CNumber &pc_new_value);
    void vFirstInit();
    int* pi_number;
    int i_length;
    bool b_sign;

};



#endif //CNUMBER_H
