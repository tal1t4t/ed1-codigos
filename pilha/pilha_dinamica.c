#include <stdio.h>
#include <stdlib.h>

#define VERD 1
#define FALSO 0

typedef struct item
{
    int numero;
    struct item *anterior;

} elemento;

void inicializar_pilha(elemento **topo);
void menu();
void mostra_pilha(elemento *topo);
int pilha_vazia(elemento **topo);
void push(elemento **topo, int n);
void pop(elemento **topo);


int main()
{
    elemento *topo;
    inicializar_pilha(&topo);

    int opcao; // para leitura da escolha do usuario
    int numero; // para leitura e exibiçao do elemento da pilha

    menu();
    scanf("%d", &opcao);

    while (opcao != 3)
    {
        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &numero);

            push(&topo, numero);
            mostra_pilha(topo);
            break;
        
        case 2:
            pop(&topo);
            mostra_pilha(topo);
            break;
        default:
            printf("Escolha inválida!");
            break;
        }
        menu();
        scanf("%d", &opcao);
    }
    return 0;
}

void inicializar_pilha(elemento **topo){
    *topo = NULL;
}

void menu(){
    printf("\n\nO que deseja fazer?\n\n[1] - Adicionar item à pilha\n\n[2] - Remover último item da pilha\n\n[3] - Sair do programa\n\n");
}

void mostra_pilha(elemento *topo){
    int i = 0;
    elemento *item;

    if(pilha_vazia(&topo))
        printf("Pilha vazia!!");
    else{
        item = topo;

        printf("\nItem     Valor       End. ativo         End. anterior\n\n");

        while (item != NULL)
        {
            i++;

            printf("[%2d] ->  %2d      :  %p          :%p\n", i, item->numero, item, item->anterior);

            item = item->anterior;
        }
        
    }
}

int pilha_vazia(elemento **topo){
    if (*topo == NULL)
        return VERD;
    else
        return FALSO;    
}

void push(elemento **topo, int n){
    elemento *novo;

    novo = (elemento *) malloc(sizeof(elemento));

    novo->numero = n;
    novo->anterior = *topo;

    *topo = novo;    
}

void pop(elemento **topo){
    elemento *antigo;

    antigo = *topo;

    if(pilha_vazia(topo))
        printf("Pilha vazia!");
    else{
        result = (*topo)->numero;
        *topo = (*topo)->anterior;

        free(antigo);
    }
}