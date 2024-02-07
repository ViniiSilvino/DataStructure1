#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 10

typedef struct objeto{

int chave;

}OBJETO;

typedef struct filaestatica{

int inicio;
int fim;
int qntElem;
OBJETO fila [TAM];

}FILA_ESTATICA;

void inicializaFilaEstatica (FILA_ESTATICA *f){
f->inicio = f-> fim = -1;
f -> qntElem = 0;
}

bool estaVazio(FILA_ESTATICA *f){
return(f->qntElem == 0);
}

bool estaCheia(FILA_ESTATICA *f){
return(f->qntElem >= TAM);
}

void insereElementoFila(FILA_ESTATICA *f, int ch){
if(estaCheia(f) == true){
printf("\nFila cheia!\n");
return;
}

if(estaVazio(f) == true){ //unica situação onde o inicio precisa ser atualizado
f->inicio = 0;
f->fim = 0;
f->qntElem++;
f->fila[f->fim].chave = ch;
printf("\nElemento: %d\n", f->fila[f->fim].chave);
return;
}

f->fim++;
if (f->fim == TAM)
{
    f->fim = 0;
}
//f->fim = (f->fim+1)%TAM;  mesma coisa das linhas 50-54

f->qntElem++;
f->fila[f->fim].chave = ch;

printf("Elemento: %d\n", f->fila[f->fim].chave);

}

void removeElemento(FILA_ESTATICA *f){

if(estaVazio(f) == true){
printf("\nFila vazia!");
return;
}

f->inicio = (f->inicio+1)%TAM;
f->qntElem--;
if(estaVazio(f) == true) inicializaFilaEstatica(f);
printf("\n__________________________________________________\n");

}

int tamanhoFila(FILA_ESTATICA *f){
return f->qntElem;
}

void imprimeFila(FILA_ESTATICA *f){
for(int i = f->inicio, cont = 0; cont < f->qntElem; cont++, i = (i+1)%TAM){
printf("\nPosicao: %d ----------- Objeto: %d", cont, f->fila[i].chave);
}
}

int main(){

    FILA_ESTATICA f;

    inicializaFilaEstatica(&f);

    insereElementoFila(&f, 42);
    insereElementoFila(&f, 5);
    insereElementoFila(&f, 54);
    insereElementoFila(&f, 24);

    imprimeFila(&f);
    printf("\n\nTamanho da fila: %d", tamanhoFila(&f));


    removeElemento(&f);

return EXIT_SUCCESS;
}