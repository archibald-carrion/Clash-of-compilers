// 253.c
// Lógica condicional en bucle (variación 4)
#include <stdlib.h>

int logica_condicional_var4() {
  int* a = malloc(sizeof(int));
  int* b = malloc(sizeof(int));
  int* c = malloc(sizeof(int));
  int* result = malloc(sizeof(int));

  if (!a || !b || !c || !result) {
    free(a);
    free(b);
    free(c);
    free(result);
    return 0;
  }

  *a = 10;
  *b = 20;
  *c = 30;
  *result = 0;

  for (long long i = 0; i < 4000000; ++i) {
    if ((*a > *b && *b > *c) || (*a < *b && *b < *c)) {
      *result += (*a + *b + *c) / 3;
    } else if ((*a + *b > *c) && (*b + *c > *a) && (*a + *c > *b)) {
      *result -= (*a ^ *b ^ *c);
    } else {
      *result *= 2;
    }
    *a = (*a * 17 + (int)i + 1) % 100;
    *b = (*b * 23 + (int)i + 2) % 150;
    *c = (*c * 29 + (int)i + 3) % 200;
    if (*result > 1000000) *result %= 1000000;
    if (*result < -1000000) *result %= 1000000;
  }

  int final_result = (*result) % 256;
  free(a);
  free(b);
  free(c);
  free(result);
  return final_result;
}

int main() {
  logica_condicional_var4();
  return 0;
}
