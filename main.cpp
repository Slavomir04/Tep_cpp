#include <iostream>
#include "src/Tool.hpp"
#include "src/Zad2/Constans.h"
#include "src/Zad2/CNumber.h"
#include <iostream>
void test(int i_new_value) {
    int i_power=0;
    int i_log_SYSTEM=1;

    bool sign = i_new_value >= 0;

    if(!sign)i_new_value = -1 * i_new_value;

    while(i_new_value % i_log_SYSTEM != i_new_value){
        i_log_SYSTEM *= cst::SYSTEM;
        i_power++;
    }
    printf("liczba: %s%i logarytm%i: %i, potega %i\n", (sign?"+":"-"), i_new_value,cst::SYSTEM,i_log_SYSTEM,i_power);

}
using namespace cst;
void test2(int i_new_value){
    int i_length=10;
    int* pi_number;


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
        i_log_SYSTEM/=SYSTEM;
        int i_current_value = i_new_value/i_log_SYSTEM;
        pi_number[i]=i_current_value;
        i_new_value-=(i_current_value*i_log_SYSTEM);
    }

    Tool::v_show_array(pi_number,i_length);
    delete[] pi_number;
}


using namespace std;
int main() {

    test2(101);


    return 0;
}
