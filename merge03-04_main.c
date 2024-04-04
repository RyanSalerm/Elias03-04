#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "merge03-04_estrutura.h"

int main()
{
  No *no;
  computando_No("Acre", 9, 0, 0, 0, no);
  computando_No("Amapá", 1, 0, 2, 1, no);
  computando_No("Amazonas", 12, 4, 24, 0, no);
  computando_No("Pará", 8, 0, 15, 0, no);
  computando_No("Rondônia", 64, 4, 15, 0, no);
  computando_No("Roraima", 0, 1, 0, 0, no);
  computando_No("Tocantis", 20, 0, 10, 0, no);
  
  //ordeando por casos casos_graves23
  //(UF, casos_graves23, obitos_dengue23, casos_graves24, obitos_dengue24)
  //mergeSort()
}