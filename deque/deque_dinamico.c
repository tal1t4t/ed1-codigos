#include <stdio.h>
#include <stdlib.h>

typedef struct el_fila
{
    struct el_fila *anterior;
    struct el_fila *proximo;

    int numero;
} elemento;

typedef struct Lista
{
    elemento *inicio;
    elemento *fim;

    int qtd;
} lista;

void limpa_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

lista *cria_lista()
{
    lista *l = (lista *)malloc(sizeof(lista));
    if (!l)
        exit(1);
    else
    {
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd = 0;
    }
    return l;
}

int deque_vazio(lista *l)
{
    if (l->qtd == 0)
        return 1;

    return 0;
}

void mostra_deque(lista *l)
{
    if (deque_vazio(l))
    {
        printf("Deque vazio! Nada a mostrar.\n");
        return;
    }

    elemento *aux = l->inicio;
    int cont = 1;

    while (aux != NULL)
    {
        printf("[%d] %d\n", cont, aux->numero);
        aux = aux->proximo;
        cont++;
    }
}

void push_front(lista *l)
{

    elemento *aux = (elemento *)malloc(sizeof(elemento));
    if (!aux)
        exit(1);

    if (deque_vazio(l))
    {
        l->fim = aux;
        aux->proximo = NULL;
    }
    else
    {
        aux->proximo = l->inicio;
        l->inicio->anterior = aux;
    }

    l->inicio = aux;
    l->qtd++;

    aux->anterior = NULL;

    printf("Digite o valor do elemento -> ");
    scanf("%d", &aux->numero);

    mostra_deque(l);
}

void push_back(lista *l)
{

    elemento *aux = (elemento *)malloc(sizeof(elemento));
    if (!aux)
        exit(1);

    if (deque_vazio(l))
    {
        aux->anterior = NULL;
        l->inicio = aux;
    }
    else
    {
        aux->anterior = l->fim;
        l->fim->proximo = aux;
    }
    l->fim = aux;
    l->qtd++;

    aux->proximo = NULL;

    printf("Digite o valor do elemento -> ");
    scanf("%d", &aux->numero);
    printf("tudo okei!!");
    mostra_deque(l);
}

void pop_front(lista *l)
{
    if (deque_vazio(l))
    {
        printf("Deque vazio! Nada para remover.");
        return;
    }
    else
    {
        elemento *aux = l->inicio;
        printf("Elemento removido: %d\n\n", aux->numero);

        if (l->inicio == l->fim) // se só tiver esse elemento na fila
        {
            l->inicio = NULL;
            l->fim = NULL;
            l->qtd--;
            printf("Esvaziou o deque!");
            return;
        }
        else
        {
            aux->proximo->anterior = NULL;
            l->inicio = l->inicio->proximo; // o que vem depois do apagado vai ser o início agora
            l->qtd--;
        }
        free(aux);
        aux = NULL;
    }

    mostra_deque(l);
}

void pop_back(lista *l)
{
    if (deque_vazio(l))
    {
        printf("Deque vazio! Nada para remover.");
        return;
    }
    else
    {
        elemento *aux = l->fim;
        printf("Elemento removido: %d\n\n", aux->numero);

        if (l->inicio == l->fim) // se só tiver esse elemento na fila
        {
            l->inicio = NULL;
            l->fim = NULL;
            l->qtd--;
            printf("Esvaziou o deque!");
            return;
        }
        else
        {
            aux->anterior->proximo = NULL;
            l->fim = l->fim->anterior; // o que vem depois do apagado vai ser o início agora
            l->qtd--;
        }
        free(aux);
        aux = NULL;
    }

    mostra_deque(l);
}

void peek_front(lista *l)
{
    printf("Primeiro elemento do deque: [%d]\n", l->inicio->numero);
}

void peek_back(lista *l)
{
    printf("Primeiro elemento do deque: [%d]\n", l->fim->numero);
}

void menu()
{
    printf("*********** DEQUE DINAMICO ***********\n\n");
    printf("O que deseja fazer?\n\n");
    printf("[1] Adicionar item no inicio do deque\n");
    printf("[2] Adicionar item no fim do deque\n");
    printf("[3] Remover item do inicio do deque\n");
    printf("[4] Remover item do fim do deque\n");
    printf("[5] Mostrar item do inicio do deque\n");
    printf("[6] Mostrar item do fim do deque\n");
    printf("[7] Exibir deque\n");
    printf("[8] Sair\n");
    printf("Opcao -> ");
}

int main()
{
    int opcao;
    lista *l = cria_lista();
    menu();
    scanf("%d", &opcao);
    while (opcao != 8)
    {
        limpa_tela();
        switch (opcao)
        {
        case 1:
            push_front(l);
            break;

        case 2:
            push_back(l);
            break;

        case 3:
            pop_front(l);
            break;

        case 4:
            pop_back(l);
            break;

        case 5:
            peek_front(l);
            break;

        case 6:
            peek_back(l);
            break;

        case 7:
            mostra_deque(l);
            break;

        default:
            if (opcao != 8)
                printf("\nOpção inválida!");
            break;
        }
        menu();
        scanf("%d", &opcao);
    }
    printf("Ate logo!");
    return 0;
}