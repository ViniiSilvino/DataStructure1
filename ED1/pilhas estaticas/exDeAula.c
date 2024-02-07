#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct objeto{
    int chave;
    //demais informações
}OBJETO;

typedef struct pilhaE{
    OBJETO *obj; 
    int tam;       //tamanho máximo da pilha
    int qtdeElem;  //qtde de elementos na pilha
    int topo;      //posicao onde esta o topo
}PILHA_ESTATICA;

void inicializaPilhaEstatica(PILHA_ESTATICA *p, int tamanho){
    p->obj= (OBJETO *) malloc(sizeof(OBJETO)*tamanho);      //p->obj é similar (*p).obj
    p->tam= tamanho;
    p->qtdeElem= 0;
    p->topo=0;
}

void destroiPilhaEstatica(PILHA_ESTATICA *p){
    free(p->obj);
}

bool estaVazia(PILHA_ESTATICA *p){
    return(p->qtdeElem==0);
}

bool estaCheia(PILHA_ESTATICA *p){
    return(p->qtdeElem==p->tam);
}

void insereElemento(PILHA_ESTATICA *p, OBJETO novo){
    if (estaCheia(p) == true)
    {
        printf("\n\nPILHA CHEIA! NAO CONSIGO INSERIR A CHAVE %d\n\n", novo.chave);
        return;
    }
    
    p->obj[p->topo]=novo;
    p->qtdeElem++;
    p->topo++;
}

void removeElemento(PILHA_ESTATICA *p){
    if (estaVazia(p) == true)
    {
        perror("\n\nPILHA VAZIA! NAO É POSSIVEL REMOVER ELEMENTO\n\n");
        return;
    }
    p->qtdeElem--;
    p->topo--;
}

void acessaTopo(PILHA_ESTATICA *p){
    if (estaVazia(p)==true)
    {
        perror("\n\nPILHA VAZIA\n\n");
        return;
    }
    
    printf("\n\n>>>TOPO: %d\n", p->obj[p->topo-1].chave);
}

void imprimeQtdeElemen(PILHA_ESTATICA *p){
    printf("\n\nQuantidade de elementos: %d\n\n", p->qtdeElem);
}

int main(void){
    PILHA_ESTATICA p;
    OBJETO aux;

    inicializaPilhaEstatica(&p, 5);
    
    aux.chave = 5;
    insereElemento(&p, aux);

    aux.chave = 8;
    insereElemento(&p, aux);

    aux.chave = 1;
    insereElemento(&p, aux);

    aux.chave = 7;
    insereElemento(&p, aux);

    aux.chave = 2;
    insereElemento(&p, aux);
    //------------------
    removeElemento(&p);
    //------------------
    acessaTopo(&p);
    //------------------
    imprimeQtdeElemen(&p);
    //------------------
    destroiPilhaEstatica(&p);

    return EXIT_SUCCESS;
}//main