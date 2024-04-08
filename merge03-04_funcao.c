#define _CRT_SECURE_NO_WARNINGS
#define MAX_DADOS 8
#include "merge03-04_estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No *computando_No() {
  FILE *arquivo = fopen("merge.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.");
    return NULL;
  }
  No *dados = malloc(MAX_DADOS *
                     sizeof(No)); // Alocar memória para o array de estruturas
  if (dados == NULL) {
    printf("Erro ao alocar memória.");
    fclose(arquivo);
    return NULL;
  }
  int contador = 0;
  while (contador < MAX_DADOS &&
         fscanf(arquivo, "%9[^,],%d,%d,%d,%d\n", dados[contador].uf,
                &dados[contador].casos_graves23,
                &dados[contador].casos_graves24,
                &dados[contador].obitos_dengue23,
                &dados[contador].obitos_dengue24) == 5) {
    contador++;
    printf("\n%d\n", contador);
  }
  fclose(arquivo);
  return dados;
}

void intercalar(No v[], int inicio, int meio, int fim) {
  int pos_inicio, pos_meio, pos_aux;
  No *aux;
  pos_inicio = inicio;
  pos_meio = meio + 1;
  pos_aux = 0;
  aux = malloc((fim - inicio + 1) * sizeof(No));

  while (pos_inicio <= meio && pos_meio <= fim) {
    if (strcmp(v[pos_inicio].uf, v[pos_meio].uf) <= 0)
      aux[pos_aux++] = v[pos_inicio++];
    else
      aux[pos_aux++] = v[pos_meio++];
  }

  while (pos_inicio <= meio)
    aux[pos_aux++] = v[pos_inicio++];

  while (pos_meio <= fim)
    aux[pos_aux++] = v[pos_meio++];

  for (pos_aux = 0; pos_aux < fim - inicio + 1; pos_aux++)
    v[inicio + pos_aux] = aux[pos_aux];

  free(aux);
}

void mergeSort(No v[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);
    intercalar(v, inicio, meio, fim);
  }
}

void imprimir(const No *dados) {
  for (int i = 0; i < MAX_DADOS - 1; i++) {
    printf("UF: %s\n", dados[i].uf);
    printf("Casos Graves 2023: %d\n", dados[i].casos_graves23);
    printf("Casos Graves 2024: %d\n", dados[i].casos_graves24);
    printf("Casos Dengue 2023: %d\n", dados[i].obitos_dengue23);
    printf("Casos Dengue 2024: %d\n", dados[i].obitos_dengue24);
    printf("\n");
  }
}
