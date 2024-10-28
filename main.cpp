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


using namespace std;
int main() {
    CNumber c1 = 15;
    CNumber c2 = -1;
    for(int i=0; i<25000; i++)c1 = c1-1;
    cout<<c1.str_str()<<endl;
    return 0;
}
