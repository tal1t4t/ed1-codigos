// Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.
#include <stdio.h>
#include <stdlib.h>

int soma_vet(int *vet, int i);

int main()
{
    int *v1, i, tam, resultado; 

    printf("Insira o tamanho do seu vetor: ");
    scanf("%d", &tam);

    v1 = (int *) malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
    {
        printf("Digite um valor para a posição [%d] : ", i);
        scanf("%d", &v1[i]);
    }
    resultado = soma_vet(v1, tam-1);
    printf("Soma dos elementos do seu vetor: %d", resultado);

    free(v1);
    return 0;
}

int soma_vet(int *vet, int i){
    if(i < 0)
        return 0;
    else{
        return vet[i] + soma_vet(vet, i-1);
    }
}