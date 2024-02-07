/*[Recurs ̃ao] Escreva e programe uma funcao recursiva para calcular o valor de um n ́umero inteiro de x
x elevada a um y inteiro y, sendo os valores de x>0 e y>0 fornecidos pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

int calcular_potencia(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * calcular_potencia(x, y - 1);
    }
}

int main() {
    int x, y;
    
    do
    {
    printf("Digite a base: ");
    scanf("%d", &x);
    } while (x < 0);
    
    
    do
    {
    printf("Digite o expoente: ");
    scanf("%d", &y);
    } while (y < 0);

    
    int resultado = calcular_potencia(x, y);
    printf("%d elevado a %d é igual a %d\n", x, y, resultado);
    
    return 0;
}//main