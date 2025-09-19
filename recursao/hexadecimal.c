#include <stdio.h>
#include <stdlib.h>

void conv_hexa(int n);

int main()
{
    int numero;
    printf("Escreva um numero na base decimal:");
    scanf("%d", &numero);

    switch (numero)
    {
    case 0:
        printf("%d", numero);
        break;

    case 1:
        printf("%d", numero);
        break;

    case 2:
        printf("%d", numero);
        break;

    case 3:
        printf("%d", numero);
        break;

    case 4:
        printf("%d", numero);
        break;

    case 5:
        printf("%d", numero);
        break;

    case 6:
        printf("%d", numero);
        break;

    case 7:
        printf("%d", numero);
        break;

    case 8:
        printf("%d", numero);
        break;

    case 9:
        printf("%d", numero);
        break;

    case 10:
        printf("A");
        break;

    case 11:
        printf("B");
        break;

    case 12:
        printf("C");
        break;

    case 13:
        printf("D");
        break;

    case 14:
        printf("E");
        break;

    case 15:
        printf("F");
        break;

    default:
        conv_hexa(numero);
        break;
    }
    return 0;
}

void conv_hexa(int n)
{
    if (n > 0)
    {
        conv_hexa(n / 16);

        switch (n%16)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;

        case 12:
            printf("C");
            break;

        case 13:
            printf("D");
            break;

        case 14:
            printf("E");
            break;

        case 15:
            printf("F");
            break;

        default:
            printf("%d", n % 16);
            break;
        }
    }
}