#define _CRT_SECURE_NO_WARNINGS
#define MAX_DADOS 8
#include "merge03-04_estrutura.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("cls");
  No *dados = computando_No();
  if (dados == NULL) {
    printf("Erro ao ler dados.\n");
    return 1;
  }
  int op;
  printf(
  "Ordenar por:\n"
  "1-UF\n"
  "2-Casos Graves 2023\n"
  "3-Casos Graves 2024\n"
  "4-Obitos por dengue 2023\n"
  "5-Obitos por dengue 2024\n"
  "6-Diferenca dos casos graves\n"
  "7-Diferenca dos obitos\n->");
  scanf("%d", &op);
  switch(op)
  {
    case 1:
    mergeSort(dados, 0, MAX_DADOS - 1, UF);
    break;

    case 2:
    mergeSort(dados, 0, MAX_DADOS - 1, CASOS_GRAVES_23);
    break;

    case 3:
    mergeSort(dados, 0, MAX_DADOS - 1, CASOS_GRAVES_24);
    break;

    case 4:
    mergeSort(dados, 0, MAX_DADOS - 1, OBITOS_23);
    break;

    case 5:
    mergeSort(dados, 0, MAX_DADOS - 1, OBITOS_24);
    break;

    case 6:
    mergeSort(dados, 0, MAX_DADOS - 1, CASOS_GRAVES_24_CASOS_GRAVES_23);
    break;

    case 7:
    mergeSort(dados, 0, MAX_DADOS - 1, OBITOS_24_OBITOS_23);
  }
  imprimir(dados);
  free(dados);

  return 0;
}