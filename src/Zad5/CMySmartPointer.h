//
// Created by Sławomir on 07.12.2024.
//

#ifndef PROGRAMY_C___TEP_CMYSMARTPOINTER_H
#define PROGRAMY_C___TEP_CMYSMARTPOINTER_H
#include <iostream>
#include "CRefCounter.h"
template<typename T>
class CMySmartPointer{
public:
    explicit CMySmartPointer(T *pcPointer);
    CMySmartPointer(CMySmartPointer &other);
    ~CMySmartPointer();
    CMySmartPointer& operator=(CMySmartPointer &other);
    CMySmartPointer& operator=(T& value);
    CMySmartPointer& operator=(T&& value);
    T& operator*();
    T* operator->();
private:
    void vSafeDealocate();
    T* pc_pointer;
    CRefCounter* pc_counter;
};





template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    pc_pointer = pcPointer;
    pc_counter = new CRefCounter();
}
template<typename T>
CMySmartPointer<T>::CMySmartPointer(CMySmartPointer &other) {
    pc_counter = other.pc_counter;
    pc_pointer = other.pc_pointer;
    pc_counter->iAdd();
}
template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    vSafeDealocate();
}

template<typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(CMySmartPointer &other) {
    if(&other != this) {
        vSafeDealocate();
        pc_counter = other.pc_counter;
        pc_pointer = other.pc_pointer;
        pc_counter->iAdd();

    }
    return *this;
}

template<typename T>
CMySmartPointer<T> & CMySmartPointer<T>::operator=(T& value) {
    if(pc_counter->iGet()%2==0) {
        *pc_pointer = value;
    }
    return *this;
}

template<typename T>
CMySmartPointer<T> & CMySmartPointer<T>::operator=(T &&value) {
    if(pc_counter->iGet()%2==1) {
        *pc_pointer = value;
    }
    return *this;
}

template<typename T>
T &CMySmartPointer<T>::operator*() {
    return(*pc_pointer);
}
template<typename T>
T *CMySmartPointer<T>::operator->() {
    return (pc_pointer);
}
template<typename T>
void CMySmartPointer<T>::vSafeDealocate() {
    pc_counter->iDec();
    if(pc_counter->iGet()==0){
        delete pc_counter;
        delete pc_pointer;

        pc_counter= nullptr;
        pc_pointer= nullptr;
    }
}


#endif //PROGRAMY_C___TEP_CMYSMARTPOINTER_H
