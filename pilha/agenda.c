#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa e as funções necessárias em Linguagem C para criar uma pilha
dinâmica de valores de uma estrutura com id (inteiro), nome e salário de um
funcionário.
*/
typedef struct agenda
{
    int id;
    char nome[70];
    float salario;
    struct agenda *anterior;
}agenda;

void inicia(agenda **topo);
void push(agenda **topo);
void menu();
void mostra(agenda **topo);
void push(agenda **topo);
void pop(agenda **topo);

int main()
{
    int opcao;

    agenda *topo;
    inicia(&topo);

    menu();
    scanf("%d", &opcao);

    while (opcao != 3)
    {
        switch (opcao)
        {
        case 1:
            push(&topo);
            mostra(&topo);
            break;
        
        case 2:
            pop(&topo);
            mostra(&topo);
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

        menu();
        scanf("%d", &opcao);
    }

    printf("Até logo!\n");

    return 0;
}

void inicia(agenda **topo){
    *topo = NULL; //definindo o topo
}

void menu(){
    printf("\n\nO que deseja fazer?\n\n[1] - Adicionar funcionário à agenda\n\n[2] - Remover último funcionário da agenda\n\n[3] - Sair do programa\n\n");
}

void mostra(agenda **topo){
    agenda *atual;
    atual = *topo;

    while (atual != NULL){
        printf("ID: %d, Nome: %s, Salario: %.2f\n", atual->id, atual->nome, atual->salario);
        atual = atual->anterior;
    }
}

void push(agenda **topo){
    agenda *novo;

    novo = (agenda *)malloc(sizeof(agenda));
    if (novo == NULL)
        printf("deu ruim ai paizao\n");
    else{
        printf("\nInsira um ID: ");
        scanf("%d", &novo->id);
        printf("\nInsira um nome: ");
        scanf("%s", novo->nome);
        printf("\nInsira um salario: ");
        scanf("%f", &novo->salario);

        novo->anterior = *topo;
        *topo = novo;
    }
}

void pop(agenda **topo){
    if (*topo == NULL)
        printf("Fila vazia\n");
    else{
        agenda *antigo;
        antigo = *topo;

        *topo = (*topo)->anterior;
        free(antigo);
    }
}