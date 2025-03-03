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
    void vCopyVec(std::vector<E*>& v_errors_other);
    T *pc_value;
    std::vector<E*> v_errors;
    bool b_succes;
};

template<typename T, typename E>
CResult<T, E>::CResult() {
        vFirstInit();
}


template<typename T, typename E>
CResult<T, E>::CResult(const T &cValue) {
    vFirstInit();
    this->pc_value = new T(cValue);
    this->b_succes=true;
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
    if(cOther.pc_value!= nullptr) {
        this->pc_value = new T(*cOther.pc_value);
    }
    vCopyVec(this->v_errors);
    /*
    for(int i=0; i<cOther.v_errors.size(); i++){
        v_errors.push_back(new E(*cOther.v_errors[i]));
    }
    */
    this->b_succes = cOther.b_succes;
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
    CResult<T,E> c_result;
    c_result.b_succes= true;
    return c_result;
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
    if(pc_value!= nullptr) {
        delete pc_value;
    }
    if(cOther.pc_value!= nullptr) {
        pc_value= new T(*cOther.pc_value);
    }
    /*
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
        v_errors.clear();
    }
    for(int i=0; i<cOther.v_errors.size(); i++) {
        v_errors.push_back(new E(*cOther.v_errors[i]));
    }
    */
   CResult<T, E>::vCopyVec(cOther.v_errors);
    return *this;
}
template<typename T, typename E>
bool CResult<T, E>::bIsSuccess() {
    return b_succes;
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
    this->b_succes= false;
}
template<typename T, typename E>
void CResult<T, E>::vCopyVec(std::vector<E*>& v_errors_other) {
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
    }
    v_errors.clear();
    for(int i=0; i<v_errors_other.size(); i++) {
        v_errors.push_back(new E(*v_errors_other[i]));
    }
}

template <typename E>
class CResult<void, E>
{
public:
    CResult();
    CResult(E *pcError);
    CResult(std::vector<E*>& vErrors);
    CResult(const CResult<void, E>& cOther);
    ~CResult();
    static CResult<void, E> cOk();
    static CResult<void, E> cFail(E* pcError);
    static CResult<void, E> cFail(std::vector<E*>& vErrors);
    CResult<void, E>& operator=(const CResult<void, E>& cOther);
    bool bIsSuccess();
    std::vector<E*>& vGetErrors();
private:
    void vFirstInit();
    void vCopyVec(std::vector<E*>& v_errors_other);
    std::vector<E*> v_errors;
    bool b_succes;
};
template<typename E>
CResult<void, E>::CResult() {
    vFirstInit();
}


template<typename E>
CResult<void, E>::CResult(E *pcError) {
    vFirstInit();
    this->v_errors.push_back(pcError);
}
template<typename E>
CResult<void, E>::CResult(std::vector<E *> &vErrors) {
    vFirstInit();
    this->v_errors = vErrors;
}

template<typename E>
CResult<void, E>::CResult(const CResult<void, E> &cOther) {
    vFirstInit();
    CResult<void, E>::vCopyVec(cOther.v_errors);
    /*
    for(int i=0; i<cOther.v_errors.size(); i++){
        v_errors.push_back(new E(*cOther.v_errors[i]));
    }
    */
    this->b_succes = cOther.b_succes;
}
template<typename E>
CResult<void, E>::~CResult() {
    for(int i=0; i<v_errors.size(); i++){
        delete v_errors[i];
    }
}
template<typename E>
CResult<void, E> CResult<void, E>::cOk() {
    CResult<void,E> c_result;
    c_result.b_succes= true;
    return c_result;
}
template<typename E>
CResult<void, E> CResult<void, E>::cFail(E *pcError) {
    return CResult<void,E>(pcError);
}
template<typename E>
CResult<void, E> CResult<void, E>::cFail(std::vector<E *> &vErrors) {
    return CResult<void,E>(vErrors);
}
template<typename E>
CResult<void, E> &CResult<void, E>::operator=(const CResult<void, E> &cOther) {
    /*
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
        v_errors.clear();
    }
    for(int i=0; i<cOther.v_errors.size(); i++) {
        v_errors.push_back(new E(*cOther.v_errors[i]));
    }
    */
    CResult<void, E>::vCopyVec(cOther.v_errors);
    return CResult<void,E>(cOther);
}
template<typename E>
bool CResult<void, E>::bIsSuccess() {
    return b_succes;
}

template<typename E>
std::vector<E *> &CResult<void, E>::vGetErrors() {
    return  v_errors;
}
template<typename E>
void CResult<void, E>::vFirstInit() {
    this->b_succes= false;
}
template<typename E>
void CResult<void, E>::vCopyVec(std::vector<E*>& v_errors_other) {
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
    }
    v_errors.clear();
    for(int i=0; i<v_errors_other.size(); i++) {
        v_errors.push_back(new E(*v_errors_other[i]));
    }
}
template<typename TE>
class CResult<TE*,TE> {
public:
    CResult();
    CResult(const CResult<TE*, TE>& cOther); //done
    ~CResult(); //done
    static CResult<TE*, TE> cOk(TE* cValue);
    static CResult<TE*, TE> cFail(TE* pcError);
    static CResult<TE*, TE> cFail(std::vector<TE*>& vErrors);
    CResult<TE*, TE>& operator=(const CResult<TE*, TE>& cOther);
    bool bIsSuccess();
    TE* cGetValue();
    std::vector<TE*>& vGetErrors();
private:
    void vFirstInit();
    void vCopyVec(const std::vector<TE*>& v_errors_other);
    TE* pc_value;
    std::vector<TE*> v_errors;
    bool b_succes;
};
template<typename TE>
CResult<TE*, TE>::CResult() {
        vFirstInit();
}

template<typename TE>
CResult<TE*, TE>::CResult(const CResult<TE*, TE> &cOther) {
    vFirstInit();
    if(cOther.pc_value != nullptr) {
        pc_value= new TE(*cOther.pc_value);
    }
    CResult<TE*, TE>::vCopyVec(cOther.v_errors);
    /*
    for(int i=0; i<cOther.v_errors.size(); i++){
        v_errors.push_back(new TE(*cOther.v_errors[i]));
    }
    */
    this->b_succes = cOther.b_succes;
}

template<typename TE>
CResult<TE*, TE>::~CResult() {
    delete pc_value;
    for(int i=0; i<v_errors.size(); i++){
        delete v_errors[i];
    }
}
template<typename TE>
CResult<TE*, TE> CResult<TE*, TE>::cOk(TE* cValue) {
    CResult<TE*, TE> c_result;
    c_result.pc_value= cValue;
    c_result.b_succes= true;
    return c_result;
}
template<typename TE>
CResult<TE*, TE> CResult<TE*, TE>::cFail(TE* pcError) {
    CResult<TE*, TE> c_result;
    c_result.v_errors.push_back(pcError);
    c_result.b_succes= false;
    return c_result;
}
template<typename TE>
CResult<TE*, TE> CResult<TE*, TE>::cFail(std::vector<TE *> &vErrors) {
    CResult<TE*, TE> c_result;
    c_result.v_errors = vErrors;
    c_result.b_succes= false;
    return c_result;
}
template<typename TE>
CResult<TE*, TE> &CResult<TE*, TE>::operator=(const CResult<TE*, TE> &cOther) {
    if(pc_value!= nullptr) {
        delete pc_value;
    }
    if(cOther.pc_value!= nullptr) {
        pc_value= new TE(*cOther.pc_value);
    }
    /*
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
        v_errors.clear();
    }
    for(int i=0; i<cOther.v_errors.size(); i++) {
        v_errors.push_back(new TE(*cOther.v_errors[i]));
    }
    */
    CResult<TE*, TE>::vCopyVec(cOther.v_errors);
    return CResult<TE*, TE>(cOther);
}
template<typename TE>
bool CResult<TE*, TE>::bIsSuccess() {
    return b_succes;
}
template<typename TE>
TE* CResult<TE*, TE>::cGetValue() {
    return pc_value;
}
template<typename TE>
std::vector<TE *> &CResult<TE*, TE>::vGetErrors() {
    return  v_errors;
}
template<typename TE>
void CResult<TE*, TE>::vFirstInit() {
    pc_value = nullptr;
    this->b_succes= false;
}

template<typename TE>
void CResult<TE*, TE>::vCopyVec(const std::vector<TE*>& v_errors_other) {
    for(int i=0; i<v_errors.size(); i++) {
        delete v_errors[i];
    }
    v_errors.clear();
    for(int i=0; i<v_errors_other.size(); i++) {
        v_errors.push_back(new TE(*v_errors_other[i]));
    }
}

#endif //PROGRAMY_C___TEP_CRESULT_H
