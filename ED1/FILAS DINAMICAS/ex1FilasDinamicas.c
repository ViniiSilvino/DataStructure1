#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct objeto{
    int chave;
    //outras informações
    struct objeto* prox;
}OBJETO;

typedef struct filadinamica{
    OBJETO * inicio;
    OBJETO* fim;
    int qtdeElem;
}FILA_DINAMICA;

int main(){


    return 0;
}