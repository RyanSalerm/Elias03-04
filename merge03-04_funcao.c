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
  }
  fclose(arquivo);
  return dados;
}

int comparar(const void *a, const void *b, ChaveOrdenacao chave) {
    const No *no1 = (const No *)a;
    const No *no2 = (const No *)b;

    switch (chave) {
        case UF:
            return strcmp(no1->uf, no2->uf);
        case CASOS_GRAVES_23:
            return no1->casos_graves23 - no2->casos_graves23;
        case CASOS_GRAVES_24:
            return no1->casos_graves24 - no2->casos_graves24;
        case OBITOS_23:
            return no1->obitos_dengue23 - no2->obitos_dengue23;
        case OBITOS_24:
            return no1->obitos_dengue24 - no2->obitos_dengue24;
        case CASOS_GRAVES_24_CASOS_GRAVES_23:
            return no1->casos_graves24 - no1->casos_graves23 - (no2->casos_graves24 - no2->casos_graves23);
        case OBITOS_24_OBITOS_23:
            return no1->obitos_dengue24 - no1->obitos_dengue23 - (no2->obitos_dengue24 - no2->obitos_dengue23);
        default:
            return 0;
    }
}

void intercalar(No v[], int inicio, int meio, int fim, ChaveOrdenacao chave) {
    int pos_inicio, pos_meio, pos_aux;
    No *aux;
    pos_inicio = inicio;
    pos_meio = meio + 1;
    pos_aux = 0;
    aux = malloc((fim - inicio + 1) * sizeof(No));

    while (pos_inicio <= meio && pos_meio <= fim) {
        if (comparar(&v[pos_inicio], &v[pos_meio], chave) <= 0)
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

void mergeSort(No v[], int inicio, int fim, ChaveOrdenacao chave) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(v, inicio, meio, chave);
    mergeSort(v, meio + 1, fim, chave);
    intercalar(v, inicio, meio, fim, chave);
  }
}

void imprimir(const No *dados) {
  for (int i = 0; i < MAX_DADOS - 1; i++) {
    printf("UF: %s\n", dados[i].uf);
    printf("Casos Graves 2023: %d\n", dados[i].casos_graves23);
    printf("Casos Graves 2024: %d\n", dados[i].casos_graves24);
    printf("Casos Dengue 2023: %d\n", dados[i].obitos_dengue23);
    printf("Casos Dengue 2024: %d\n", dados[i].obitos_dengue24);
    printf("Diferenca de Casos: %d\n", dados[i].casos_graves24 - dados[i].casos_graves23);
    printf("Diferenca de Obitos: %d\n", dados[i].obitos_dengue24 - dados[i].obitos_dengue23);
    printf("\n");
  }
}
