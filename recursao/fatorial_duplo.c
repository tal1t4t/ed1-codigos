#include <stdio.h>
//#include <locale.h>

int fat_duplo(int n){
    // caso base
    if (n == 1){
        return 1;
    } else {
        int mult;
        // chamada recursiva
        mult = n * fat_duplo(n-2);
        return mult;
    }
}

int main(){
//    setlocale(LC_ALL, "");
    int n, resultado;

    scanf("%d", &n);
    while (n % 2 == 0){
        printf("Numero invalido! Digite um numero IMPAR: ");
        scanf("%d", &n);
    }
         
    printf("\n");

    resultado = fat_duplo(n);

    printf("%d\n", resultado);

    return 0;
}