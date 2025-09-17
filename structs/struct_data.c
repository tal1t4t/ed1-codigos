#include <stdio.h>

struct s_data
{
    int dia, mes, ano;
};

typedef struct s_data sdata;

int main(){

    sdata data, *pdata;
    pdata = &data;

    printf("Digite um dia, mês e ano:");
    scanf("%d", &pdata->dia); // é o mesmo que  scanf("%d", data.dia);, sem utilizar o ponteiro
    while (pdata->dia < 1 || pdata->dia > 31)
    {
        printf("insira um dia válido!");
        scanf("%d", &pdata->dia);
    }
    
    /* 
    outra forma de atribuir um valor pelo ponteiro da struct:
    scanf("%d", (*pdata).dia);
    */
    scanf("%d", &pdata->mes);
    scanf("%d", &pdata->ano);
    

    printf("\n\nData inserida: %d/%d/%d", (*pdata).dia, (*pdata).mes, (*pdata).ano);
    
    return 0;
}