//
// Created by slawe on 22.10.2024.
//

#include "CNumber.h"

#include <cmath>
#include <iostream>
#include "../Tool.hpp"
using namespace cst;
void CNumber::vFirstInit() {

    i_length = NUMBER_DEFAULT_LENGTH;
    pi_number = new int[NUMBER_DEFAULT_LENGTH]{};
    b_sign = true;
    vTrim();
}

CNumber::CNumber() {
    vFirstInit();
}

CNumber::CNumber(int i_value) {
    vFirstInit();
    vSet(i_value);
}
CNumber::CNumber(const CNumber &pc_value_to_copy) {
    vFirstInit();
    vCopy(pc_value_to_copy);
}

CNumber::~CNumber() {
    delete[] pi_number;
}

void CNumber::vSet(int i_new_value) {

    int i_power=0;
    long l_new_value = i_new_value;
    long l_log_SYSTEM=1;
    long l_SYSTEM = (long )SYSTEM;
    b_sign = i_new_value >= 0;

    if(!b_sign)l_new_value = -1 * l_new_value;

    while(i_new_value % l_log_SYSTEM != i_new_value){
        l_log_SYSTEM *= l_SYSTEM;
        i_power++;
    }

    delete[] pi_number; //Uzywanie delete na nullptr nie posiada konsekwencji wiec jest bezpieczne
    i_length = i_power!=0?i_power:1;
    pi_number = new int[i_length];


    for(int i=0; i<i_length; i++){
        l_log_SYSTEM = l_log_SYSTEM/l_SYSTEM;
        if(l_log_SYSTEM==0){
            l_log_SYSTEM=1;
        }
        long l_current_value = l_new_value/l_log_SYSTEM;
        pi_number[i] = (int)l_current_value;
        l_new_value -= (l_current_value*l_log_SYSTEM);
    }

}

void CNumber::operator=(const CNumber &pc_new_value) {
    if(&pc_new_value != this) {
        vCopy(pc_new_value);
    }
}

CNumber CNumber::operator+(const CNumber &pc_other) {
    if(this->b_sign == pc_other.b_sign){
        return cAddTwoNumbers(pc_other, 0);
    }else{
        if(bIsBigger(pc_other, 0)){
            return cSubtractTwoNumbers(pc_other);
        }else{
            return pc_other.cSubtractTwoNumbers(*this);
        }
    }
}

CNumber CNumber::operator-(const CNumber &pc_other) {
   if(this->b_sign == pc_other.b_sign){
       if(bIsBigger(pc_other, 0)){
           return cSubtractTwoNumbers(pc_other);
       }else{
           CNumber temp(pc_other.cSubtractTwoNumbers(*this));
           temp.b_sign = !temp.b_sign;
           return temp;
       }
   }else{
       return cAddTwoNumbers(pc_other, 0);
   }
}

CNumber CNumber::operator*(const CNumber &pc_other) {
    return cMultiplyTwoNumbers(pc_other);
}

CNumber CNumber::operator/(const CNumber &pc_other) {
    return cDivideTwoNumbers(pc_other);
}

void CNumber::operator=(int i_new_value) {
    return (*this=CNumber(i_new_value));
}

CNumber CNumber::operator+(int i_other) {
    return (*this+CNumber(i_other));
}

CNumber CNumber::operator-(int i_other) {
    return (*this-CNumber(i_other));
}

CNumber CNumber::operator*(int i_other) {
    return cMultiplyTwoNumbers(CNumber(i_other));
}

CNumber CNumber::operator/(int i_other) {
    return cDivideTwoNumbers(CNumber(i_other));
}

std::string CNumber::str_str() {

    std::stringstream ss;
    ss<<(b_sign||pi_number[0]==0?" ":"-");
    for(int i=0; i<i_length; i++) {
        ss<<pi_number[i];
    }
    return ss.str();
}

CNumber CNumber::cAddTwoNumbers(const CNumber &pc_other, int i_displacement) const{
    int* pi_result;
    int i_length_result;

    i_length_result = ((this->i_length > pc_other.i_length + i_displacement) ? this->i_length : pc_other.i_length + i_displacement) + 1;

    pi_result = new int[i_length_result];

    const int* pi_other = pc_other.pi_number;
    int i_length_other = pc_other.i_length;
    vAddArrays(pi_result,i_length_result,0,pi_other,i_length_other,i_displacement);

    CNumber CResult;
    CResult.i_length = i_length_result;
    delete[] CResult.pi_number;
    CResult.pi_number = pi_result;
    CResult.b_sign = this->b_sign;

    CResult.vTrim();
    return CResult;
}

CNumber CNumber::cSubtractTwoNumbers(const CNumber &pc_other) const{
    int* pi_result;
    int i_length_result;

    i_length_result = (this->i_length > pc_other.i_length) ? this->i_length : pc_other.i_length;

    pi_result = new int[i_length_result];

    const int* pi_other=pc_other.pi_number;
    int i_length_other = pc_other.i_length;
    vSubArrays(pi_result,i_length_result,pi_other,i_length_other);

    CNumber CResult;
    CResult.i_length = i_length_result;
    delete[] CResult.pi_number;
    CResult.pi_number = pi_result;
    CResult.b_sign = this->b_sign;

    CResult.vTrim();
    return CResult;
}

CNumber CNumber::cMultiplyTwoNumbers(const CNumber &pc_other) const{
    /*
    CNumber temp(pc_other);
    temp.b_sign= true;
    CNumber temp_number_1(1);
    CNumber result(0);
    while (temp.bIsBigger(temp_number_1,0)){
        temp = temp - temp_number_1;
        result = result + *this;
    }
    result.b_sign =  (this->b_sign == pc_other.b_sign);
    return result;
     */
    bool b_sign_result = this->b_sign == pc_other.b_sign;
    int i_length_result = this->i_length + pc_other.i_length;
    int* pi_array_result = new int[i_length_result];
    const int* pi_number_other = pc_other.pi_number;
    vMulArrays(pi_array_result,i_length_result,pi_number_other,pc_other.i_length);

    CNumber result;
    result.i_length = i_length_result;
    result.pi_number = pi_array_result;
    result.b_sign = b_sign_result;
    result.vTrim();
    return result;
}
CNumber CNumber::cDivideTwoNumbers(const CNumber &pc_other) const {
    if(pc_other.i_length == 1 && pc_other.pi_number[0] == 0){
        return CNumber(0);
    }else {

        CNumber result(0);


        CNumber zero(0);
        CNumber one(1);

        CNumber nomiator(*this);
        nomiator.b_sign = true;

        CNumber divider(pc_other);
        divider.b_sign = true;

        while (nomiator.b_sign && nomiator.bIsBigger(zero, 0)) {
            nomiator = nomiator - divider;

            if (nomiator.b_sign) {
                result = result + one;
            }
        }
        result.b_sign = this->b_sign == pc_other.b_sign;
        return result;
    }
}

void CNumber::vAddArrays(int* &pi_result, int i_length_result,int i_displacement_this, const int* &pi_other, const int i_length_other, int i_displacement_other) const{


    int i_accumulator = 0;

    int i_shift_this = i_length_result - this->i_length;
    int i_shift_other = i_length_result - i_length_other;

    for(int i= i_length_result - 1; i >= 0; i--) {

        int i_index_this = i-i_shift_this + i_displacement_this;
        int i_index_other = i-i_shift_other + i_displacement_other;

        if(i_index_this>=0 && (i_length_result - 1 - i_displacement_this) >= i ) {
            i_accumulator+=this->pi_number[i_index_this];
        }
        if(i_index_other>=0 && (i_length_result - 1 - i_displacement_other) >= i ) {
            i_accumulator+=pi_other[i_index_other];
        }
        pi_result[i]=i_accumulator%SYSTEM;
        i_accumulator/=SYSTEM;
    }
}

void CNumber::vSubArrays(int *&pi_result, int i_length_result, const int *&pi_other, const int i_length_other) const{

    const int i_shift_to_result = i_length_result - this->i_length;

    for(int i=0; i < i_length_result; i++) {
        pi_result[i+i_shift_to_result]=pi_number[i];
    }

    const int i_shift = this->i_length - i_length_other;

    for(int i=i_length_other-1; i>=0; i--) {
        pi_result[i+i_shift+i_shift_to_result] -= pi_other[i];
        if(pi_result[i+i_shift+i_shift_to_result]<0) {
            bool b_done = false;
            for(int y=i+i_shift+i_shift_to_result-1; y>=0 && !b_done; y--) {
                pi_result[y]--;pi_result[y+1]+=SYSTEM;
                b_done = pi_result[y]>=0;
            }
        }
    }
}
void CNumber::vMulArrays(int* &pi_result, int i_length_result, const int *&pi_other, const int i_length_other) const{
    for(int i=0; i<i_length_result; i++){
        pi_result[i]=0;
    }
    for(int i=0; i<i_length_other; i++) {
        for(int ii=0; ii < pi_other[i]; ii++){
            int* pi_temp = new int[i_length_result];
            for(int i_index_copy=0; i_index_copy<i_length_result; i_index_copy++){
                pi_temp[i_index_copy]=pi_result[i_index_copy];
            }
            int i_system_shift =(i_length_other - 1 - i);

            const int* pi_result_temp = pi_result;
            vAddArrays(pi_temp,i_length_result,i_system_shift,pi_result_temp,i_length_result,0);

            delete[] pi_result;
            pi_result = pi_temp;
        }
    }
}


bool CNumber::bIsBigger(const CNumber &pc_other, int i_displacement) const{
    /*
    if(this->i_length > pc_other.i_length) {
        return true;
    }else if(this->i_length < pc_other.i_length) {
        return false;
    }else {
        bool b_result;
        bool b_loop=true;
        for(int i=0; i<this->i_length && b_loop; i++) {
            if(this->pi_number[i]!=pc_other.pi_number[i]){
                b_result = this->pi_number[i] > pc_other.pi_number[i];
                b_loop= false;
            }
        }
        return b_result;
    }
     */
    if(this->i_length > pc_other.i_length + i_displacement) {
        return true;
    }else if(this->i_length < pc_other.i_length + i_displacement) {
        return false;
    }else {
        bool b_result= true;
        bool b_loop= true;
        for(int i=0; i<this->i_length && b_loop; i++){
            int div = this->pi_number[i];
            if(i < pc_other.i_length){
                div -= pc_other.pi_number[i];
            }
            if(div!=0){
                b_result = div>0;
                b_loop= false;
            }
        }
        return b_result;
    }
}



void CNumber::vTrim() {
    int i_zeroes=0;
    bool loop=true;
    for(int i=0; i<i_length&&loop; i++) {
        if(pi_number[i]==0) {
            i_zeroes++;
        }
        else {
            loop=false;
        }
    }
    if(i_zeroes>0) {
        if(i_zeroes==i_length) {
            int* pi_new=new int[1]{0};
            delete[] pi_number;
            pi_number=pi_new;
            i_length=1;
        }
        else {
            int i_length_new = i_length-i_zeroes;
            int* pi_number_new = new int[i_length_new];
            for(int i=0; i<i_length_new; i++) {
                pi_number_new[i] = pi_number[i+i_zeroes];
            }
            delete[] pi_number;
            pi_number = pi_number_new;
            i_length = i_length_new;
        }
    }
}

void CNumber::vCopy(const CNumber &pc_new_value) {
    delete[] pi_number;
    this->i_length = pc_new_value.i_length;
    this->pi_number = new int[this->i_length];
    this->b_sign = pc_new_value.b_sign;
    for(int i=0; i<this->i_length; i++) {
        pi_number[i]=pc_new_value.pi_number[i];
    }
}




















