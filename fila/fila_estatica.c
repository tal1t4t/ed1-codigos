#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define VERD 1
#define FALSO 0
#define ERRO -1

/* Convenções:
inicio = 0 e termino = -1
inicio > termino indica fila vazia.
termino = (TAM_VET – 1) indica fila cheia
*/

int exibe_menu();
void exibe_vet(int inicio, int fim, int vet[]);
int fila_cheia(int fim);
int fila_vazia(int inicio, int fim);
void enqueue(int inicio, int *final, int vet[]);
void dequeue(int *inicio, int termino, int vet[]);
int fila_acabou(int inicio);

int main()
{
    int inicio = 0, termino = -1; // valores usados por convenção
    int vet[TAM], resp;

    resp = exibe_menu();
    while (resp != 3)
    {
        switch (resp)
        {
        case 1:
            enqueue(inicio, &termino, vet);
            break;

        case 2:
            dequeue(&inicio, termino, vet);
            if (fila_acabou(inicio))
            {
                printf("A fila terminou!");
                return 0;
            }
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }
        resp = exibe_menu();
    }

    printf("Até logo!");

    return 0;
}

int exibe_menu()
{
    int op;
    printf("    O que deseja fazer?\n\n[1] - Adicionar item\n\n[2] - Remover item\n\n[3] - Encerrar programa\n\n");
    scanf("%d", &op);

    return op;
}

void exibe_vet(int inicio, int fim, int vet[])
{
    int i;
    printf("\n");
    for (i = inicio; i <= fim; i++)
        printf("[%d]: %d\n", i, vet[i]);
}

int fila_cheia(int fim)
{
    if (fim == TAM - 1)
        return VERD;
    else
        return FALSO;
}

int fila_vazia(int inicio, int fim)
{
    if (inicio > fim)
        return VERD;
    else
        return FALSO;
}

void enqueue(int inicio, int *final, int vet[])
{
    if (fila_cheia(*final))
        printf("Fila cheia! - Remova algum valor para inserir outro\n");
    else
    {
        (*final)++;
        int n;
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &n);
        vet[*final] = n;
        exibe_vet(inicio, *final, vet);
    }
}

void dequeue(int *inicio, int termino, int vet[])
{
    if (fila_vazia(*inicio, termino))
        printf("Fila vazia! Insira um valor para remover depois.\n");
    else
    {
        (*inicio)++;
        exibe_vet(*inicio, termino, vet);
    }
}

int fila_acabou(int inicio)
{
    if (inicio == TAM)
        return VERD;
    else
        return FALSO;
}