#define _CRT_SECURE_NO_WARNINGS
#define MAX_DADOS 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "merge03-04_estrutura.h"

void computando_No(No* aux)
{
   FILE *arquivo = fopen("merge.txt", "r");
   if (arquivo == NULL) {
       printf("Erro ao abrir o arquivo.");
   }
   No dados[MAX_DADOS]; 
   int contador = 0;
   while (fscanf(arquivo, "%s,%d,%d,%d,%d", &dados[contador].uf, &dados[contador].casos_graves23, dados[contador].casos_graves24, dados[contador].obitos_dengue24) == 5) 
   {
       contador++;
   }
   fclose(arquivo);
  
  strcmp(aux->uf, dados[contador].uf) == 0);
  aux->casos_graves23 = dados[contador].casos_graves23;
  aux->casos_graves24 = dados[contador].casos_graves24;
  aux->obitos_dengue23 = dados[contador].obitos_dengue23;
  aux->obitos_dengue24 = dados[contador].obitos_dengue24;

}

void intercalar(int v[], int inicio, int meio, int fim)
{
  int *aux, pos_inicio, pos_meio, pos_aux;
  pos_inicio = inicio;
  pos_meio = meio;
  pos_aux = 0;
  aux = malloc(fim*sizeof(*v));
  while((pos_inicio < meio+1) || (pos_meio < fim +1))
  {
    if(pos_inicio == meio+1)
    {
      aux[pos_aux] = v[pos_meio];
      pos_meio++;
      pos_aux++;
    }
    else if(pos_meio == fim+1)
    {
      aux[pos_meio] = v[pos_inicio];
      pos_inicio++;
      pos_aux++;
    }
    else if(v[pos_inicio] <= v[pos_meio])
    {
      aux[pos_meio] = v[pos_inicio];
      pos_inicio++;
      pos_aux++;
    }
    else
    {
      aux[pos_aux] = v[pos_meio];
      pos_meio++;
      pos_aux++;
    }
  }
  for(pos_inicio = inicio; pos_inicio <= fim; pos_inicio++)
  {
    v[pos_inicio] = aux[(pos_inicio-inicio)];
  }
  free(aux);
}
void mergeSort(int v[], int inicio, int fim)
{
  if(inicio < fim)
  {
    int meio = inicio + (fim - inicio)/2;
    mergeSort(v, inicio, fim);
    mergeSort(v, meio+1, fim);
    intercalar(v, inicio, meio, fim);
  }
}


