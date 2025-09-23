#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main()
{

    int n, soma;
    do
    { // garantindo que a quantidade de termos seja válida
        printf("Digite a quanitdade limite de termos da sua sequência: ");
        scanf("%d", n);
    } while (n <= 0);

    soma = fibonacci(n);
    printf("%d", soma);

    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else{
        int resultado;
        // retorna a soma dos dois elementos anteriores(alguma hora vai chegar no caso base)
        resultado = fibonacci(n - 1) + fibonacci(n - 2);
    }    
}