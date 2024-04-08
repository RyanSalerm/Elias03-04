#include "merge03-04_estrutura.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  No *dados = computando_No();
  if (dados == NULL) {
    printf("Erro ao ler dados.\n");
    return 1;
  }
  // mergeSort(no, 0, 6);
  imprimir(dados);
  free(dados);
  return 0;
}