//
// Created by Sławomir on 07.12.2024.
//

#ifndef PROGRAMY_C___TEP_CREFCOUNTER_H
#define PROGRAMY_C___TEP_CREFCOUNTER_H


class CRefCounter {
public:
    CRefCounter();
    int iAdd();
    int iDec();
    int iGet();
private:
    int i_count;
};


#endif //PROGRAMY_C___TEP_CREFCOUNTER_H
