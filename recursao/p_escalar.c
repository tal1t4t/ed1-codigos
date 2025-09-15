#include <stdio.h>
#include <stdlib.h>
// #include <locale.h>

void ler_vetor(float *vet, int n);

float escalar(float *v1, float *v2, int n);

int main(){

    // setlocale(LC_ALL, "Portuguese");

    float *v1, *v2, res;
    int dim;

    printf("\n\nInsira o numero de dimensoes do seu vetor: ");
    scanf("%d", &dim);

    v1 =  (float*) malloc(dim * sizeof(float));
    v2 =  (float*) malloc(dim * sizeof(float));

    if ((v1 == NULL) || (v2 == NULL)) { /* verificação de erro */
        printf("Erro na alocacao de memoria!\n");        
        return 1;
    }

    printf("\n\nInsira as coordenadas do primeiro vetor:");
    ler_vetor(v1, dim);

    printf("\n\nInsira as coordenadas do segundo vetor:");
    ler_vetor(v2, dim);

    res = escalar(v1, v2, dim-1);

    printf("\nproduto escalar: %.3f\n", res);

    free(v1);
    free(v2);

    return 0;
}

void ler_vetor(float *vet, int n){
    int i;
    for (i = 0; i < n; i++){
        printf("\n%da coordenada: ", i+1);
        scanf("%f", &vet[i]);
    }
}

float escalar(float *v1, float *v2, int n){
    if (n == 0){
        return (v1[n] * v2[n]);
    }else{
        float resultado = (v1[n] * v2[n]) + escalar(v1, v2, n-1);
        return resultado;
    }
}