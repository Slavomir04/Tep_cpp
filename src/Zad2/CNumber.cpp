//
// Created by slawe on 22.10.2024.
//

#include "CNumber.h"
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
        // i_ln = SYSTEM^(i_power-1) np. nasz 10^(i_power-1)
        if(i_new_value < 0) {
            i_new_value = -1*i_new_value;
            b_is_neg=true;
        }else b_is_neg=false;
        int i_ln=1;
        int i_power=0;
        while(i_new_value%i_ln!=i_new_value) {
            i_ln*=SYSTEM;
            i_power++;
        }
        i_ln= i_ln>SYSTEM?(i_ln/SYSTEM):1;

        delete[] pi_number; //usuwanie pointera null nic nie daje, wiec mozna uzyc bez konsekwencji
        i_length=i_power>0?i_power:1;
        pi_number = new int[i_length];

        for(int i=0; i<i_length; i++) {
            int i_temp = i_new_value/i_ln;
            pi_number[i]=i_temp;
            i_new_value = i_new_value - i_temp*i_ln;
            i_ln/=SYSTEM;
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

const CNumber CNumber::operator+(CNumber &pc_new_value) {
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

const CNumber CNumber::operator-(CNumber &pc_new_value) {
}

const CNumber CNumber::operator*(CNumber &pc_new_value) {
}

const CNumber CNumber::operator/(CNumber &pc_new_value) {
}

void CNumber::operator=(int i_new_value) {
}

const CNumber CNumber::operator+(int i_new_value) {
}

const CNumber CNumber::operator-(int i_new_value) {
}

const CNumber CNumber::operator*(int i_new_value) {
}

const CNumber CNumber::operator/(int i_new_value) {
}

std::string CNumber::str_str() {
    std::stringstream ss;
    for(int i=0; i<i_length; i++) {
        ss<<pi_number[i];
    }
    return ss.str();
}


