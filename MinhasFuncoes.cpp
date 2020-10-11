#include "MinhasFuncoes.h"

int IsIn (int chave, int* v, int length) {
    for (int i=0; i < length; i++) {
        if (chave == v[i]) 
            return i;
    }
    return -1;
}

int IsInBinarioRecursivo (int chave, int* v, int baixo, int alto) {    
    int meio;
    
    if (baixo > alto) {
        return -1;
    }
    else {
        meio = (baixo + alto)/2;
  
        if (v[meio] == chave) 
            return meio;
        else if (v[meio] < chave) 
            return IsInBinarioRecursivo(chave, v, meio+1, alto);
        else
            return IsInBinarioRecursivo(chave, v, baixo, meio-1);
    }
}