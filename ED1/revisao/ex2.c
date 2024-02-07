/*Faca um programa que receba, por argumento na main, o nome de um arquivo texto. Crie
outro arquivo texto de saıda contendo o texto do arquivo de entrada original, por ́em substituindo todas
as vogais ‘a’ pelo caractere ‘*’ e as demais vogais por ‘+’. Alem disso, mostre na tela quantas linhas
esse arquivo possui. Dentro do programa fa ̧ca o controle de erros, isto  ́e, insira comandos que mostre se
os arquivos foram abertos com sucesso e, caso contr ́ario, imprima uma mensagem de erro encerrando o
programa.
OBS: Utilizar passagem de parˆametros (argC e argV) para receber o nome do arquivo.txt.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char caractere;
    int linhas;

    FILE* arq = fopen("aquivo.dat", "w+");

    if (arq == NULL)
    {

        perror("!!!!");
        exit(1);
    }
    
    do {
        caractere = fgetc(arq);
        if(caractere == '\n') {
            linhas++;
        }

    printf("numero de linhas: %d", linhas);
    
        switch (caractere)
        {
        case 'a':
        case 'A':
            fprintf(arq,"*");
        break;

        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            fprintf(arq, "+");
        break;

        default:
            break;
        }
    } while(caractere != EOF);


    return 0;
}//main