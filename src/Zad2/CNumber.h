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
    CNumber(const CNumber &pc_value_to_copy);
    ~CNumber();

    void vSet(int i_new_value);
    void operator=(const CNumber &pc_new_other);
    CNumber operator+(const CNumber &pc_new_other);
    CNumber operator-(const CNumber &pc_new_other);
    CNumber operator*(const CNumber &pc_new_other);
    CNumber operator/(const CNumber &pc_new_other);


    void operator=(int i_new_value);
    CNumber operator+(int i_new_other);
    CNumber operator-(int i_new_other);
    CNumber operator*(int i_new_other);
    CNumber operator/(int i_new_other);



    std::string str_str();



//private:
    CNumber addTwoNumbers(const CNumber &pc_new_other,int i_displacement) const; //two number must have same sign, other number with displacement must be maximum 1SYstem bigger from this
    CNumber subtractTwoNumbers(const CNumber &pc_new_other) const; //two number cannot have same sign
    CNumber multiplyTwoNumbers(const CNumber &pc_new_other) const;
    CNumber divideTwoNumbers(const CNumber &pc_new_other) const;
    void vAddArrays(int* &pi_result,int i_size_result,const int* &pi_other,const int i_length_other,int i_displacement) const; // add some array to this array and results are in result array
    void vSubArrays(int* &pi_result, int i_size_result, const int* &pi_other, const int i_length_other) const; // sub always small from bigger
    bool bIsBigger(const CNumber &pc_new_other,int i_displacement) const;
    void vTrim();
    void v_Copy(const CNumber &pc_new_value);
    void vFirstInit();
    int* pi_number;
    int i_length;
    bool b_sign;

};



#endif //CNUMBER_H
