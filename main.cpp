#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad2/Constans.h"
#include "src/Zad2/CNumber.h"
#include <cmath>
#include <iostream>

int vTrim(int* &pi_number,int i_length) {
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
    return i_length;
}

void vAddArrays(int *&pi_result, int i_size_result,int* &pi_this,int i_length_this,int i_displacement_this,int* &pi_other, int i_length_other,int i_displacement_other){
    const int SYSTEM = 10;
    int i_accumulator = 0;

    int i_shift_this = i_size_result-i_length_this;
    int i_shift_other = i_size_result-i_length_other;

    for(int i=i_size_result-1; i>=0; i--) {

        int i_index_this = i-i_shift_this + i_displacement_this;
        int i_index_other = i-i_shift_other + i_displacement_other;

        if(i_index_this>=0 && (i_size_result-1 - i_displacement_this) >= i) {
            i_accumulator+=pi_this[i_index_this];
        }
        if(i_index_other>=0 && (i_size_result-1 - i_displacement_other) >= i ) {
            i_accumulator+=pi_other[i_index_other];
        }
        pi_result[i]=i_accumulator%SYSTEM;
        i_accumulator/=SYSTEM;
    }
}

void vSubArrays(int *&pi_result, int i_size_result,int* &pi_this,int i_length_this, int *&pi_other, int i_length_other) {

    const int SYSTEM = 10;


    const int i_shift_to_result = i_size_result - i_length_this;

    for(int i=0; i<i_size_result; i++) {
        pi_result[i+i_shift_to_result]=pi_this[i];
    }

    const int i_shift = i_length_this - i_length_other;

    for(int i=i_length_other-1; i>=0; i--) {
        int i_index_result = i+i_shift+i_shift_to_result;
        pi_result[i_index_result] -= pi_other[i];
        if(pi_result[i+i_shift+i_shift_to_result]<0) {
            bool b_done = false;
            for(int y=i+i_shift+i_shift_to_result-1; y>=0 && !b_done; y--) {
                pi_result[y]--;pi_result[y+1]+=SYSTEM;
                b_done = pi_result[y]>=0;
            }
        }
    }
}

bool bIsBigger(int* pi_this,int i_length_this,int* pi_other,int i_length_other,int i_displacement){
    if(i_length_this > i_length_other+i_displacement) {
        return true;
    }else if(i_length_this < i_length_other+i_displacement) {
        return false;
    }else {
        bool b_result= true;
        bool b_loop= true;
       for(int i=0; i<i_length_this && b_loop; i++){
           int div = pi_this[i];
           if(i<i_length_other){
               div -= pi_other[i];
           }
           if(div!=0){
               b_result = div>0;
               b_loop= false;
           }
       }
        return b_result;
    }
}

void vMullTwoNumber(int *&pi_result, int i_size_result,int* &pi_this,int i_length_this,int* &pi_other, int i_length_other){
    /*
    for(int i=0; i<i_length_this; i++) {
        for (int ii = 0; ii < pi_this[i]; ii++) {
            int *pi_temp = new int[i_size_result];
            for (int i_index_copy = 0; i_index_copy < i_size_result; i_index_copy++) {
                pi_temp[i_index_copy] = pi_result[i_index_copy];
            }
            int i_system_shift = (i_length_this - 1 - i);
            vAddArrays(pi_temp, i_size_result, pi_result, i_size_result,0, pi_other, i_length_other, i_system_shift);
            delete[] pi_result;
            pi_result = pi_temp;
        }
    }
    */


    for(int i=0; i<i_length_other; i++) {
        for(int ii=0; ii < pi_other[i]; ii++){
            int* pi_temp = new int[i_size_result];
            for(int i_index_copy=0; i_index_copy<i_size_result; i_index_copy++){
                pi_temp[i_index_copy]=pi_result[i_index_copy];
            }
            int i_system_shift =(i_length_other - 1 - i);
            vAddArrays(pi_temp,i_size_result,pi_this,i_length_this,i_system_shift,pi_result,i_size_result,0);
            delete[] pi_result;
            pi_result = pi_temp;
        }
    }

}



using namespace std;
int main() {






    cout<<(CNumber(379)-CNumber(999)).str_str()<<endl;
    cout<<(CNumber(379)+CNumber(-999)).str_str()<<endl;
    cout<<(CNumber(1000)-CNumber(22)).str_str()<<endl;
    cout<<(CNumber(999)+CNumber(1)).str_str()<<endl;
    cout<<(CNumber(37)*CNumber(-11)).str_str()<<endl;
    cout<<(CNumber(-99)*CNumber(-2)).str_str()<<endl;
    cout<<(CNumber(121)*CNumber(3012)).str_str()<<endl;
    cout<<(CNumber(INT_MAX)*CNumber(INT_MAX)).str_str()<<endl;
    cout<<(CNumber(364452)/CNumber(13)).str_str()<<endl;
    cout<<(CNumber(3448182)/CNumber(-123)).str_str()<<endl;
    cout<<(CNumber(-89998)/CNumber(-7777)).str_str()<<endl;

    CNumber c_test(128);
    c_test^=4;
    cout<<"c_test: "<<c_test.str_str()<<endl;

}
