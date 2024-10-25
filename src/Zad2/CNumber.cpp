//
// Created by slawe on 22.10.2024.
//
#include <cmath>
#include "CNumber.h"
using namespace cst;
void CNumber::vFirstInit() {

    i_length = NUMBER_DEFAULT_LENGTH;
    pi_number = new int[NUMBER_DEFAULT_LENGTH]{};

}

CNumber::CNumber() {
    vFirstInit();
}

CNumber::~CNumber() {
    delete[] pi_number;
}

void CNumber::vSet(int i_new_value) {
    int i_power=0;
    int i_log_SYSTEM=1;

    bool sign = i_new_value >= 0;

    if(!sign)i_new_value = -1 * i_new_value;

    while(i_new_value % i_log_SYSTEM != i_new_value){
        i_log_SYSTEM *= cst::SYSTEM;
        i_power++;
    }

    delete[] pi_number; //Uzywanie delete na nullptr nie posiada konsekwencji wiec jest bezpieczne
    i_length = i_power!=0?i_power:1;
    pi_number = new int[i_length];




    for(int i=0; i<i_length; i++){
        i_log_SYSTEM*=SYSTEM;
        int i_current_value = i_new_value/i_log_SYSTEM;
        pi_number[i]=i_current_value;
        i_new_value-=(i_current_value*i_log_SYSTEM);
    }

}

void CNumber::operator=(const CNumber &pc_new_value) {
    delete[] pi_number;
    this->i_length = pc_new_value.i_length;
    this->pi_number = new int[this->i_length];
    this->b_is_neg = pc_new_value.b_is_neg;
    for(int i=0; i<this->i_length; i++) {
        pi_number[i]=pc_new_value.pi_number[i];
    }
}

CNumber CNumber::operator+(CNumber &pc_new_value) {
    const int i_prefix = b_is_neg?-1:1;
    const int i_prefix_pc_new_value = b_is_neg?-1:1;

    int i_size = this->i_length>pc_new_value.i_length?this->i_length:pc_new_value.i_length;
    int* pi_array = new int[i_size];

    int i_previous=0;
    for(int i=0; i<i_size; i++) {
        if(i<i_length && i<pc_new_value.i_length) {
            pi_array[i]=i_prefix*pi_number[i]+i_prefix_pc_new_value*pi_number[i]+i_previous;
            i_previous = pi_array[i]/SYSTEM;
            if(i_previous!=0) {
                pi_array[i]=pi_array[i]%SYSTEM;
            }
        }else if(i<i_length) {
            
        }else if(i<pc_new_value.i_length) {

        }
    }
}

CNumber CNumber::operator-(CNumber &pc_new_value) {
}

CNumber CNumber::operator*(CNumber &pc_new_value) {
}

CNumber CNumber::operator/(CNumber &pc_new_value) {
}

void CNumber::operator=(int i_new_value) {

}

CNumber CNumber::operator+(int i_new_value) {
}

CNumber CNumber::operator-(int i_new_value) {
}

CNumber CNumber::operator*(int i_new_value) {
}

CNumber CNumber::operator/(int i_new_value) {
}

std::string CNumber::str_str() {
    std::stringstream ss;
    for(int i=0; i<i_length; i++) {
        ss<<pi_number[i];
    }
    return ss.str();
}




