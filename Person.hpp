//
// Created by slawe on 06.10.2024.
//

#ifndef PROGRAMY_C___TEP_PERSON_HPP
#define PROGRAMY_C___TEP_PERSON_HPP
#include <iostream>
#include <sstream>

class Person {
public:
    Person(){
        str_name="no name";
        i_value_len=0;
        pi_values=nullptr;
    }
    Person(std::string str_name,int i_values_len)
    {
        this->str_name = str_name;
        this->i_value_len = i_values_len>0 ? i_values_len : 0;
        alloc_values();
    }


    ~Person(){
        if(pi_values != nullptr)delete[] pi_values;
    }

    Person& operator=(const Person& other){
        this->~Person();
        str_name = other.str_name;
        i_value_len = other.i_value_len;
        pi_values = new int[i_value_len];
        for(int i=0; i<i_value_len; i++){
            pi_values[i]=other.pi_values[i];
        }
        return *this;
    }

    bool add(int value,int pos)
    {
        if(pos>0 && pos<i_value_len)
        {
            pi_values[pos]=value;
            return true;
        }else return false;
    }
    std::string c_str()
    {
        const char c_shift=' ';
        std::stringstream ss;
        ss<<str_name<<'{';
        for(int i=0; i<i_value_len; i++){
            ss<<pi_values[i]<<c_shift;
        }
        ss<<'\b'<<'}';
        return ss.str();
    }
protected:
    std::string str_name;
    int* pi_values;
    int i_value_len;

    void alloc_values()
    {
        pi_values = new int[i_value_len];
        for(int i=0; i<i_value_len; i++){
            pi_values[i]=0;
        }
    }
};


#endif //PROGRAMY_C___TEP_PERSON_HPP
