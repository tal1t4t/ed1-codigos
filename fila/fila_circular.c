#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERRO 0

int exibe_menu();
void mostra_fila(int vet[], int inicio, int f);
int insere(int tam, int *fim, int *t_fila, int vet[]);
int tira(int tam, int *inicio, int *t_fila, int vet[]);

int main()
{
    int tam, final = -1, inicio = 0, tam_fila = 0, resp, ok;

    printf("Insira o tamanho da sua fila: ");
    scanf("%d", &tam);

    int vet[tam];

    resp = exibe_menu();

    while (resp != 3)
    {
        switch (resp)
        {
        case 1:
            ok = insere(tam, &final, &tam_fila, vet);
            if(ok == 1)
                mostra_fila(vet, inicio, final);
            break;
        
        case 2:
            ok = tira(tam, &inicio, &tam_fila, vet);
            if(ok == 1 && tam_fila != 0)
                mostra_fila(vet, inicio, final);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

        resp = exibe_menu();
    }
    
    printf("Até logo!\n");
    return 0;
}

int exibe_menu()
{
    int op;
    printf("        O que deseja fazer?\n\n[1] - Adicionar item\n\n[2] - Remover item\n\n[3] - Encerrar programa\n\n");
    scanf("%d", &op);

    return op;
}

void mostra_fila(int vet[], int inicio, int f){
    int i;
    for (i = inicio; i <= f; i++)
    {
        printf("Elemento [%d] = %d\n", i, vet[i]);
    }
}

int insere(int tam, int *fim, int *t_fila, int vet[]){
    if (*t_fila == tam)
    {
        printf("Fila cheia!\n");
        return ERRO;
    }else{
        printf("Digite um valor: ");
        scanf("%d", &vet[(*fim + 1) % tam]);

        (*t_fila)++;
        *fim = (*fim + 1) % tam;
        return OK;
    }   
}

int tira(int tam, int *inicio, int *t_fila, int vet[]){
    if (*t_fila == 0)
    {
        printf("Fila vazia!\n");
        return ERRO;
    }else{
        printf("Elemento removido: %d\n", vet[*inicio]);

        *inicio = (*inicio + 1) % tam;
        (*t_fila)--;

        return OK;
    }    
}