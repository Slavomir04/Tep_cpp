//
// Created by Sławomir on 07.12.2024.
//

#include "CRefCounter.h"


CRefCounter::CRefCounter() {
    i_count=1;
}

int CRefCounter::iAdd() {
     return(++i_count);
}

int CRefCounter::iDec() {
     return(--i_count);
}

int CRefCounter::iGet() {
    return(i_count);
}
