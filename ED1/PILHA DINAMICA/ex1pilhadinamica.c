#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Obj
{
    int chave;
    //colocar mais informações necessarias
    struct Obj* prox;   //armazena o elemento que entrou antes dele
}OBJETO;

typedef struct
{
    OBJETO* topo;
    int qtdeElem;
}PILHA_DINAMICA;

void inicializaPilha(PILHA_DINAMICA *p)
{
    p->topo = NULL;
    p->qtdeElem = 0;
}

bool estaVazia(PILHA_DINAMICA *p)
{
        return p->qtdeElem == 0;     //ou topo ser NULL        
}

int tamanhoPilha(PILHA_DINAMICA *p)
{    
    return p->qtdeElem;
}

void empilhaPilha(PILHA_DINAMICA *p, int chave)
{
    OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO) * 1);
    if (aux == NULL)
    {
        perror("ERRO DE ALOCACAO DE MEMORIA EM empilhaPilha");
        return;
    }
    aux->chave = chave;
    aux->prox = p->topo;
    p->topo = aux;
    p->qtdeElem++;
}

void imprimeTopo(PILHA_DINAMICA *p)
{
    if (estaVazia(p) == true)
    {
        perror("\n\nPILHA VAZIA!!\n\n");
        return;
    }
    printf("\n\n>>>TOPO: %d <<<", p->topo->chave);
}

void destroiPilha(PILHA_DINAMICA *p)
{
    OBJETO* aux = p->topo;
    while (aux != NULL)
    {
        p->topo = aux->prox;
        free(aux);
        aux = p->topo;

    }
    p->qtdeElem = 0;  
}

void desempilhaPilha(PILHA_DINAMICA *p)
{
    OBJETO* aux = p->topo;

    if (aux == NULL) return;

        p->topo = aux->prox;
        free(aux);
    
        p->qtdeElem--;  
}

void imprimeElementosPilha(PILHA_DINAMICA *p)
{
    printf("\n\n");
    for (OBJETO* aux=p->topo; aux!= NULL; aux = aux->prox)
    {
        printf("%d", aux->chave);
    }

}

int main()
{

    PILHA_DINAMICA p;

    inicializaPilha(&p);

    empilhaPilha(&p,5);
    empilhaPilha(&p,2);
    empilhaPilha(&p,8);
    empilhaPilha(&p,1);
    empilhaPilha(&p,3);
    empilhaPilha(&p,6);

    imprimeTopo(&p);

    //desempilhaPilha(&p);
    
    imprimeElementosPilha(&p);

    destroiPilha(&p);

    imprimeTopo(&p);

    return 0;
}//main