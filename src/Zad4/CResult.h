//
// Created by Sławomir on 22.11.2024.
//

#ifndef PROGRAMY_C___TEP_CRESULT_H
#define PROGRAMY_C___TEP_CRESULT_H
#include <vector>
#include <string>
template <typename T, typename E>
class CResult
{
public:
    CResult();
    CResult(const T& cValue); //done
    CResult(E* pcError);    //done
    CResult(std::vector<E*>& vErrors); //done
    CResult(const CResult<T, E>& cOther); //done
    ~CResult(); //done
    static CResult<T, E> cOk();
    static CResult<T, E> cOk(const T& cValue);
    static CResult<T, E> cFail(E* pcError);
    static CResult<T, E> cFail(std::vector<E*>& vErrors);
    CResult<T, E>& operator=(const CResult<T, E>& cOther);
    bool bIsSuccess();
    T cGetValue();
    std::vector<E*>& vGetErrors();
private:
    void vFirstInit();
    T *pc_value;
    std::vector<E*> v_errors;
};

template<typename T, typename E>
CResult<T, E>::CResult() {
        vFirstInit();
}


template<typename T, typename E>
CResult<T, E>::CResult(const T &cValue) {
    vFirstInit();
    this->pc_value = new T(cValue);
}
template<typename T, typename E>
CResult<T, E>::CResult(E *pcError) {
    vFirstInit();
    this->v_errors.push_back(pcError);
}
template<typename T, typename E>
CResult<T, E>::CResult(std::vector<E *> &vErrors) {
    vFirstInit();
    this->v_errors = vErrors;
}

template<typename T, typename E>
CResult<T, E>::CResult(const CResult<T, E> &cOther) {
    vFirstInit();
    this->pc_value = T(cOther.pc_value);
    for(int i=0; i<cOther.v_errors.size(); i++){
        v_errors.push_back(E(cOther.v_errors[i]));
    }
}
template<typename T, typename E>
CResult<T, E>::~CResult() {
    delete pc_value;
    for(int i=0; i<v_errors.size(); i++){
        delete v_errors[i];
    }
}
template<typename T, typename E>
CResult<T, E> CResult<T, E>::cOk() {
    return CResult<T,E>();
}
template<typename T, typename E>
CResult<T, E> CResult<T, E>::cOk(const T &cValue) {
    return CResult(cValue);
}
template<typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(E *pcError) {
    return CResult(pcError);
}
template<typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(std::vector<E *> &vErrors) {
    return CResult(vErrors);
}
template<typename T, typename E>
CResult<T, E> &CResult<T, E>::operator=(const CResult<T, E> &cOther) {
    return CResult(cOther);
}
template<typename T, typename E>
bool CResult<T, E>::bIsSuccess() {
    return v_errors.empty();
}
template<typename T, typename E>
T CResult<T, E>::cGetValue() {
    if(pc_value!= nullptr){
        return *pc_value;
    }else{
        return T();
    }
}
template<typename T, typename E>
std::vector<E *> &CResult<T, E>::vGetErrors() {
    return  v_errors;
}
template<typename T, typename E>
void CResult<T, E>::vFirstInit() {
    pc_value = nullptr;
}

#endif //PROGRAMY_C___TEP_CRESULT_H
