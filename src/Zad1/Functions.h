//
// Created by slawe on 21.10.2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

inline void v_alloc_table_fill_34(int iSize){

    const int i_FillValue=34;
    const char c_shift=',';
    if(iSize<=0){

    }else{
        int* pi_pointer = new int[iSize];
        for(int i=0; i<iSize; i++){
            pi_pointer[i]=i_FillValue;
        }

        for(int i=0; i<iSize; i++){
            std::cout<<pi_pointer[i]<<c_shift;
        }
        std::cout<<"\n";

        delete[] pi_pointer;
    }
}

inline bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
    if(iSizeX<=0 || iSizeY<=0){
        return false;
    }else{
        *piTable = new int*[iSizeX];
        for(int i=0; i<iSizeX; i++){
            (*piTable)[i]=new int[iSizeY];
        }
        return true;
    }
}

inline bool b_dealloc_table_2_dim(int*** piTable, int iSizeX,int iSizeY) {
    if(iSizeX<=0 || iSizeY<=0){
        return false;
    }else{
        for(int i=0; i<iSizeX; i++){
            delete[] (*piTable)[i];
        }
        delete[] *piTable;
        return true;
    }
}





#endif //FUNCTIONS_H
