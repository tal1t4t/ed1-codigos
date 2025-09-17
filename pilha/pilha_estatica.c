#include <stdio.h>
#include <stdlib.h>

#define VERD 1
#define FALSO 0
#define ERRO -1

int push(int *topo, int *pilha, int dado, int tam);
int pop(int *topo, int *pilha);
int pilha_cheia(int *topo, int tam);
int pilha_vazia(int *topo);
int exibe_menu();
void exibe_pilha(int *pilha, int topo);

int main()
{
    int tam, topo = -1, opcao, dado, ok;

    printf("Insira o tamanho do seu vetor: ");
    scanf("%d", &tam);
    int pilha[tam];

    // op 1 acrescenta item, op 2 tira, op3 exibe a pilha, op4 sai do programa
    opcao = exibe_menu();
    while (opcao != 4)
    {
        if (opcao == 1)
        {
            printf("Insira um número: ");
            scanf("%d", &dado);
            push(&topo, pilha, dado, tam);
        }
        else if (opcao == 2)
        {
            ok = pop(&topo, pilha);
            if (ok != ERRO)
                printf("Item removido com sucesso!\n");
        }
        else if(opcao == 3)
        {
            exibe_pilha(pilha, topo);
        }

        opcao = exibe_menu();
    }
    printf("Até logo!\n");
    return 0;
}

int pilha_cheia(int *topo, int tam)
{
    if (*topo == tam - 1)
        return VERD;
    else
        return FALSO;
}

int pilha_vazia(int *topo)
{
    if (*topo == -1)
        return VERD;
    else
        return FALSO;
}

int exibe_menu()
{
    int op;

    printf("\n\nO que deseja fazer?\n\n[1] - Adicionar item à pilha\n\n[2] - Remover último item da pilha\n\n[3] - Exibir pilha atual\n\n[4] - Sair do programa\n\n");

    scanf("%d", &op);

    while ((op != 1) && (op != 2) && (op != 3) && (op != 4))
    {
        printf("\n\nOpção inválida! Insira um dos números mostrados no menu.\n");
        scanf("%d", &op);
    }

    return op;
}

void exibe_pilha(int *pilha, int topo){
    int i;
    for (i = topo; i >= 0; i--)
    {
        printf("Item [%d]: %d\n", i, pilha[i]);
    }
}

int push(int *topo, int *pilha, int dado, int tam)
{
    if (pilha_cheia(topo, tam))
    {
        printf("ERRO: Pilha cheia. Remova um valor para inserir outro.");
        return ERRO;
    }
    else
    {
        (*topo)++;
        pilha[*topo] = dado;
    }
    return VERD;
}

int pop(int *topo, int *pilha)
{
    // perguntar pro max por que usar *topo dá problema no código(nao entendi a resposta do gpt)
    if (pilha_vazia(topo)){ 
        printf("ERRO: pilha vazia");
        return ERRO;
    }
    else
    {
        pilha[*topo] = 0;
        (*topo)--;
        return VERD;
    }
}