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
        l_log_SYSTEM=  l_log_SYSTEM/l_SYSTEM;
        if(l_log_SYSTEM==0) l_log_SYSTEM=1;
        long l_current_value = l_new_value/l_log_SYSTEM;
        pi_number[i]=(int)l_current_value;
        l_new_value-=(l_current_value*l_log_SYSTEM);
    }


}

void CNumber::operator=(const CNumber &pc_new_value) {
    if(&pc_new_value!=this) {
        v_Copy(pc_new_value);
    }
}

CNumber CNumber::operator+(const CNumber &pc_new_value) {
    if(this->b_sign == pc_new_value.b_sign) {
        return addTwoNumbers(pc_new_value);
    }else {
        return subtractTwoNumbers(pc_new_value);
    }
}

CNumber CNumber::operator-(const CNumber &pc_new_value) {
    if(this->b_sign != pc_new_value.b_sign) {
        return addTwoNumbers(pc_new_value);
    }else {
        return subtractTwoNumbers(pc_new_value);
    }
}

CNumber CNumber::operator*(const CNumber &pc_new_value) {
}

CNumber CNumber::operator/(const CNumber &pc_new_value) {
}

void CNumber::operator=(int i_new_value) {
    CNumber temp = CNumber(i_new_value);
    return (*this=temp);
}

CNumber CNumber::operator+(int i_new_value) {
    CNumber temp = CNumber(i_new_value);
    return (*this+temp);
}

CNumber CNumber::operator-(int i_new_value) {
    CNumber temp = CNumber(i_new_value);
    return (*this-temp);
}

CNumber CNumber::operator*(int i_new_value) {
}

CNumber CNumber::operator/(int i_new_value) {
}

std::string CNumber::str_str() {

    std::stringstream ss;
    ss<<(b_sign?" ":"-");
    for(int i=0; i<i_length; i++) {
        ss<<pi_number[i];
    }
    return ss.str();
}

CNumber CNumber::addTwoNumbers(const CNumber &pc_new_value) {
    /*
    int* pi_array;
    int i_length_new;

    if(this->i_length>pc_new_value.i_length) {
        i_length_new = this->i_length+1;
    }else {
        i_length_new = pc_new_value.i_length+1;
    }
    pi_array = new int[i_length_new];

    if(this->i_length == i_length_new-1) {
        const int i_shift = this->i_length - pc_new_value.i_length;
        int i_accumulator = 0;
        for(int i=pc_new_value.i_length-1; i>=0; i--) {
            i_accumulator += this->pi_number[i+i_shift] + pc_new_value.pi_number[i];

            pi_array[i+i_shift+1] = i_accumulator%SYSTEM;
            i_accumulator/=SYSTEM;
        }
        for(int i=i_shift-1; i>=0; i--) {
            i_accumulator += this->pi_number[i];
            pi_array[i+1] = i_accumulator%SYSTEM;
            i_accumulator/=SYSTEM;
        }
        pi_array[0] = i_accumulator;
    }else {
        const int i_shift =  pc_new_value.i_length - this->i_length;
        int i_accumulator = 0;
        for(int i=this->i_length-1; i>=0; i--) {
            i_accumulator += pc_new_value.pi_number[i+i_shift] + this->pi_number[i];

            pi_array[i+i_shift+1] = i_accumulator%SYSTEM;
            i_accumulator/=SYSTEM;
        }
        for(int i=i_shift-1; i>=0; i--) {
            i_accumulator += pc_new_value.pi_number[i];
            pi_array[i+1] = i_accumulator%SYSTEM;
            i_accumulator/=SYSTEM;
        }
        pi_array[0] = i_accumulator;
    }


    CNumber resultCNumber;
    resultCNumber.i_length = i_length_new;
    resultCNumber.pi_number = pi_array;
    resultCNumber.b_sign = (i_length_new-1 == this->i_length ? this->b_sign:pc_new_value.b_sign);
    resultCNumber.vTrim();
    return resultCNumber;
    */
    int* pi_array;
    int i_array_length;
    if(this->i_length>pc_new_value.i_length) {
        i_array_length = this->i_length;
    }else {
        i_array_length = pc_new_value.i_length;
    }
    pi_array = new int[i_array_length];
    vAddArrays(pi_array,i_array_length,pc_new_value.pi_number,pc_new_value.i_length);
}

CNumber CNumber::subtractTwoNumbers(const CNumber &pc_new_value) {
    bool b_final_sign = b_sign; // true: this >= pc_new_value
    int i_length_larger = i_length;
    int* pi_array;
    if(this->i_length > pc_new_value.i_length) {
        i_length_larger=this->i_length;
        b_final_sign=true;
    }else if(this->i_length < pc_new_value.i_length) {
        i_length_larger=pc_new_value.i_length;
        b_final_sign=false;
    }else {
        for(int i=i_length-1; i>=0; i--) {
            if(this->pi_number[i]<pc_new_value.pi_number[i]) {
                b_final_sign=false;
                i_length_larger=pc_new_value.i_length;
                i=-1;
            }else if(this->pi_number[i]>pc_new_value.pi_number[i]) {
                b_final_sign=true;
                i_length_larger=this->i_length;
                i=-1;
            }
        }
    }

    pi_array = new int[i_length_larger];

    if(b_final_sign) {
        for(int i=0; i<i_length_larger; i++) {
            pi_array[i]=pi_number[i];
        }

        const int i_shift = this->i_length - pc_new_value.i_length;

        for(int i=pc_new_value.i_length-1; i>=0; i--) {
            pi_array[i+i_shift] -= pc_new_value.pi_number[i];
            if(pi_array[i+i_shift]<0) {
                bool b_done = false;
                for(int y=i+i_shift-1; y>=0 && !b_done; y--) {
                    pi_array[y]--;
                    pi_array[y+1]+=SYSTEM;
                    b_done = pi_array[y]>=0;
                }
            }
        }
    }else {
        for(int i=0; i<i_length_larger; i++) {
            pi_array[i]=pc_new_value.pi_number[i];
        }

        const int i_shift =  pc_new_value.i_length - this->i_length;

        for(int i=this->i_length-1; i>=0; i--) {
            pi_array[i+i_shift] -= this->pi_number[i];
            if(pi_array[i+i_shift]<0) {
                bool b_done = false;
                for(int y=i+i_shift-1; y>=0 && !b_done; y--) {
                    pi_array[y]--;
                    pi_array[y+1]+=SYSTEM;
                    b_done = pi_array[y]>=0;
                }
            }
        }
    }

    CNumber resultCNumber;
    resultCNumber.i_length = i_length_larger;
    resultCNumber.pi_number = pi_array;
    resultCNumber.b_sign = b_final_sign;
    if(b_final_sign == this->b_sign) {
        resultCNumber.b_sign = true;
    }else {
        resultCNumber.b_sign = this->b_sign && b_final_sign;
    }
    resultCNumber.vTrim();
    return resultCNumber;
}

CNumber CNumber::multiplyTwoNumbers(const CNumber &pc_new_value) {
    int* pi_array;
    int i_length_new = this->i_length*pc_new_value.i_length;
    bool b_final_sign = this->b_sign == pc_new_value.b_sign;

    pi_array = new int[i_length_new];

    if(i_length_new >= pc_new_value.i_length) {  // bigger +=smaller[i]*10^n



    }else {


    }
}

void CNumber::vAddArrays(int *&pi_result, int i_size_result,int* &pi_other, int i_length_other) {
    int i_accumulator = 0;
    int i_shift_this = i_size_result-this->i_length;
    int i_shift_other = i_size_result-i_length_other;
    for(int i=i_size_result-1; i>=0; i--) {
        int i_index_this = i-i_shift_this;
        int i_index_other = i-i_shift_other;
        if(i_index_this>=0) {
            i_accumulator+=pi_number[i_index_this];
        }
        if(i_index_other>=0) {
            i_accumulator+=pi_other[i_index_other];
        }
        pi_result[i]=i_accumulator%SYSTEM;
        i_accumulator/=SYSTEM;
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

void CNumber::v_Copy(const CNumber &pc_new_value) {
    delete[] pi_number;
    this->i_length = pc_new_value.i_length;
    this->pi_number = new int[this->i_length];
    this->b_sign = pc_new_value.b_sign;
    for(int i=0; i<this->i_length; i++) {
        pi_number[i]=pc_new_value.pi_number[i];
    }
}






