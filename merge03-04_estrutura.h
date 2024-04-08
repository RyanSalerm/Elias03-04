typedef struct {
  char uf[10];
  int casos_graves23;
  int obitos_dengue23;
  int casos_graves24;
  int obitos_dengue24;
} No;

No *computando_No();
void intercalar(No v[], int inicio, int meio, int fim);
void mergeSort(No v[], int inicio, int fim);
void imprimir(const No *aux);