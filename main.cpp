#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad2/CNumber.h"

void test(int i_new_value) {
    int i_ln=1;
    int i_power=0;
    while(i_new_value%i_ln!=i_new_value) {
        i_ln*=10;
        i_power++;
    }
    i_ln/=10;
    for(int i=0; i<i_power; i++) {
        int i_value_pos = i_new_value/i_ln;

        std::cout<<i_value_pos<<" ";

        i_new_value = i_new_value - i_value_pos*i_ln;
        i_ln/=10;
    }
}


using namespace std;
int main() {


    CNumber number1;
    CNumber number2;
    number1.vSet(5);
    number2.vSet(5);

    cout<<().str_str()<<'\n';
    return 0;
}
