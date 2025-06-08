// 257.c
// Suma/resta aritmética en un bucle (variación 9)
#include <stdlib.h>

int suma_resta_var9() {
  int* suma_a = malloc(sizeof(int));
  int* suma_b = malloc(sizeof(int));

  if (!suma_a || !suma_b) {
    free(suma_a);
    free(suma_b);
    return 0;
  }

  *suma_a = 0;
  *suma_b = 0;

  for (long long i = 1; i <= 1000000; ++i) {
    *suma_a += i;
    *suma_b -= i;
    if (i % 10000 == 0) {  // Interleave dependency
      *suma_a += ((*suma_b) / ((int)(i / 10000) + 1));
      *suma_b -= ((*suma_a) / ((int)(i / 10000) + 2));
    }
  }

  int result = (int)(((*suma_a) ^ (*suma_b)) % 256);
  free(suma_a);
  free(suma_b);
  return result;
}

int main() {
  suma_resta_var9();
  return 0;
}
