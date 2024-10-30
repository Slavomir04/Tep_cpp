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
    CNumber(long i_value);
    CNumber(const CNumber &pc_value_to_copy);
    ~CNumber();

    void vSet(long l_new_value);
    void operator=(const CNumber &pc_new_value);
    CNumber operator+(const CNumber &pc_other);
    CNumber operator-(const CNumber &pc_other);
    CNumber operator*(const CNumber &pc_other);
    CNumber operator/(const CNumber &pc_other);


    void operator=(int i_new_value);
    CNumber operator+(int i_other);
    CNumber operator-(int i_other);
    CNumber operator*(int i_other);
    CNumber operator/(int i_other);

    void operator^=(int i_new_system);

    std::string str_str();



private:
    CNumber cAddTwoNumbers(const CNumber &pc_other, int i_displacement) const; //two number must have same sign, other number with displacement must be maximum 1SYstem bigger from this
    CNumber cSubtractTwoNumbers(const CNumber &pc_other) const; //two number cannot have same sign
    CNumber cMultiplyTwoNumbers(const CNumber &pc_other) const;
    CNumber cDivideTwoNumbers(const CNumber &pc_other) const;
    void vAddArrays(int* &pi_result, int i_length_result,int i_displacement_this, const int* &pi_other, const int i_length_other, int i_displacement_other) const; // add some array to this array and results are in result array
    void vSubArrays(int* &pi_result, int i_length_result, const int* &pi_other, const int i_length_other) const; // sub always small from bigger
    void vMulArrays(int* &pi_result, int i_length_result, const int* &pi_other, const int i_length_other)const;
    bool bIsBigger(const CNumber &pc_other, int i_displacement) const;
    bool bIsSame(const CNumber &pc_other) const;
    void vTrim();
    void vCopy(const CNumber &pc_new_value);
    void vFirstInit();
    int* pi_number;
    int i_length;
    bool b_sign;

};



#endif //CNUMBER_H
