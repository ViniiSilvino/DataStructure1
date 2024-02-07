#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int RA;
}ALUNO;

int* alocaMemoria(int num){
    return (int*) malloc(sizeof (int*) * num);
}

void valor(int val, int* p){
    *p = val;
}

ALUNO* alocaMemoriaAlunos(int total){
    return (ALUNO*) malloc(sizeof(ALUNO*) * total);
}

// void insereDados1(int total, ALUNO* a){

//     for (int i = 0; i < total; i++)
//     {
//         printf("Digite o nome do %do aluno: ", i+1);
//         scanf("%s", a[i].nome);
//         setbuf(stdin, NULL);

//         printf("Digite o RA de %s: ", a[i].nome);
//         scanf("%d", &a[i].RA);
//         setbuf(stdin, NULL);   
//     }//for

// }//insere dados 1 

void insereDados2(int total, ALUNO* a){

    for (int i = 0; i < total; i++)
    {
        printf("\nDigite o nome do %do aluno: ", i+1);
        scanf("%s", a[i].nome);
        setbuf(stdin, NULL);

        printf("Digite o RA de %s: ", a[i].nome);
        scanf("%d", &a[i].RA);
        setbuf(stdin, NULL);
    }//for


}//insere dados 2

int main(){

    //STRUCT, ALOCAÇÃO DE MEMORIA E PONTEIRO
    ALUNO *a;
    int total = 3;
    a = alocaMemoriaAlunos(total);
 //   insereDados1(total, &a);
    insereDados2(total, a);




    int *p;
    p = alocaMemoria(1);

    valor(13,p);
    printf("\n\n\n%d\n\n\n", *p);

    free(a);
    free(p);
    
    return EXIT_SUCCESS;
}