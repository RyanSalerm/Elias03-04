typedef struct {
  char uf[10];
  int casos_graves23;
  int obitos_dengue23;
  int casos_graves24;
  int obitos_dengue24;
} No;
typedef enum {
    UF,
    CASOS_GRAVES_23,
    CASOS_GRAVES_24,
    OBITOS_23,
    OBITOS_24,
    CASOS_GRAVES_24_CASOS_GRAVES_23,
    OBITOS_24_OBITOS_23
} ChaveOrdenacao;

No *computando_No();
void intercalar(No v[], int inicio, int meio, int fim, ChaveOrdenacao chave);
void mergeSort(No v[], int inicio, int fim, ChaveOrdenacao chave);
void imprimir(const No *aux);