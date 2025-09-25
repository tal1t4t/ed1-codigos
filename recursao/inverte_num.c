#include <stdio.h>
#include <stdlib.h>

// Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

void inverte(int n);

int main(){

    int n;
    scanf("%d", &n);

    inverte(n);
    return 0;
}

void inverte (int n){
    printf("%d", n % 10);
    if ((n / 10) != 0){
        inverte(n / 10);    
    }
} 

/*
32 / 10 = 3 resta 2
3 / 10 = 0 resta 3

*/