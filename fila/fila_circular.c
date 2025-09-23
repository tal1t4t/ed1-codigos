#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int inicio, termino, tamanho, elemento[10];
};

int main()
{

    int i;
    struct fila F;

    F.inicio = 0;
    F.termino = -1;
    F.tamanho = 0;

    if (F.tamanho <= 10)
    {
        for (i = 0; i < 10; i++)
        {
            printf("\nDigite o elemento a ser inserido na fila: ");
            scanf("%d", &F.elemento[(F.termino % 10) + 1]);
            F.termino = (F.termino % 10) + 1;
            F.tamanho++;
        }
    }

    else
        printf("Fila cheia!");

    printf("\n");
    printf("Inicio da Fila esta na posicao: %d \n", F.inicio);
    printf("Termino da Fila esta na posicao: %d \n", F.termino);
    printf(" O tamanho da Fila é : %d \n", F.tamanho);
    printf("\n");

    /* remoção de 3 elementos da fila circular */
    if (F.tamanho >= 3)
    {
        for (i = 0; i <= 2; i++)
        {
            printf("Elemento removido: %d \n", F.elemento[F.inicio]);
            F.inicio = (F.inicio + 1) % 10;
            F.tamanho = F.tamanho + 1;
        }
    }

    else
        printf("Remoção inválida.");
    printf("\n");

    /*inserção de 2 elementos da fila circular */
    if (F.tamanho <= 8)
    {
        for (i = 0; i < 2; i++)
        {
            printf("Insira um valor na fila: ");
            scanf("%d", &F.elemento[(F.termino % 10) + 1]);
            F.termino = (F.termino) + 1;
            F.tamanho = F.tamanho + 1;
        }
    }
    else
        printf("Fila cheia");

    printf("\n");
    printf("Inicio da Fila esta na posicao: %d \n", F.inicio);
    printf("Termino da Fila esta na posicao: %d \n", F.termino);
    printf(" O tamanho da Fila : %d \n", F.tamanho);

    return 0;
}