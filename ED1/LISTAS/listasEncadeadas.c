#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Objeto{
    int chave;
    //demois infos
    struct Objeto* prox; //SIMPLESMENTE ENCADEADA
}OBJETO;

typedef struct ListaEncadeada{
    OBJETO* inicio;
    int qtdeElem;
}LISTA_ENCADEADA;

void inicializaLista(LISTA_ENCADEADA* lista)
{


}

bool estaVazia(LISTA_ENCADEADA* lista)
{
    return lista->qtdeElem == 0;
}

void insereElem(LISTA_ENCADEADA* lista)
{


}











int main(){
    LISTA_ENCADEADA lista;

    inicializaLista(&lista);



    return 0;
}//main