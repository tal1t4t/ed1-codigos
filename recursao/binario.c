#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void converte_binario (int k) {

  if (k != 0) { 
    converte_binario(k/2);
    printf("%d", k%2);
  }
}

int main () {

  int numero;
  printf("Escreva um numero na base decimal:");
  scanf("%d", &numero);
  
  if (numero == 1) {
    printf("1");  
  } else if (numero==0){
    printf("0");
  } else {
  converte_binario(numero);
  }

  
  return 0;
}