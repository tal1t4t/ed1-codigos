#include <stdio.h>
#include <stdlib.h>

int escolha; // variavel pra processar oq o usuário quer fazer

typedef struct Elemento_FILA
{
    int valor;
    struct Elemento_FILA *proximo;
} Elemento_fila;

// controle da fila
typedef struct Fila
{
    Elemento_fila *inicio;
    Elemento_fila *fim;
} fila;

fila *criar_fila()
{
    fila *f = (fila *)malloc(sizeof(fila));
    if (!f)
        exit(1);
    else
    {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(fila *f)
{
    // fila não inicializada ou início aponta pra NULL
    if (f == NULL || f->inicio == NULL)
        return 1;
    else
        return 0;
}

void mostra_fila(fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila vazia!\n");
        printf("\nEnd. início:  %p", f->inicio);
        printf("\nEnd. final:   %p", f->fim);
        return;
    }

    Elemento_fila *aux = f->inicio;
    printf("\nFila atual: ");
    printf("\n Fila End. Inicio %p: ", f->inicio);
    printf("\n Fila End. Fim %p: ", f->fim);
    printf("\n");

    while (aux != NULL)
    {
        printf("\n\tValor:  %3d \tEndereco: %p ===> %p", aux->valor, aux, aux->proximo);
        aux = aux->proximo;
    }
}

int menu()
{
    printf("\n Opções da Fila;\n");
    printf(" 0 Sair;\n");
    printf(" 1 Inserir na Fila;\n");
    printf(" 2 Retirar da Fila;\n");
    printf(" Escolha: ");
    scanf("%i", &escolha);
    return escolha;
}

void enfileirar(fila *f)
{
    int n;
    printf("Insira um valor: ");
    scanf("%d", &n);

    Elemento_fila *el_fila = (Elemento_fila *)malloc(sizeof(Elemento_fila));
    if (!el_fila)
        exit(1);
    else
    {
        el_fila->valor = n;
        if (f->inicio == NULL)//se a fila estiver vazia, o endereço do início é o endereço do elemento inserido
            f->inicio = el_fila;
        else{
            // f->fim->proximo pega o endereço do elemento anterior para apontar para o atual
            f->fim->proximo = el_fila;
        }
        el_fila->proximo = NULL;
        f->fim = el_fila;//o fim da fila aponta para o novo elemento
    }
}

void desenfileirar(fila *f){
    if(!fila_vazia(f)){
        // guarda o endereço do primeiro elemento pra liberar depois
        Elemento_fila *no_fila = f->inicio;

        // define o próximo elemento na fila como o primeiro
        f->inicio = f->inicio->proximo;
        
        //libera o elemento apagado
        free(no_fila);
    }
}

void opcoes(int escolha, fila *f)
{
    switch (escolha)
    {
    case 1:
        enfileirar(f);
        mostra_fila(f);
        break;

    case 2:
        desenfileirar(f);
        mostra_fila(f);
        break;

    default:
        if (escolha != 0)
            printf("Opcao invalida!!!\n");
    }
}

int main()
{
    fila *f = criar_fila();
    mostra_fila(f);
    do
    {
        escolha = menu();
        opcoes(escolha, f);
    } while (escolha);

    free(f);
    return 0;
}