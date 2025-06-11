// 265.c
// Lógica condicional en bucle (variación 6)
#include <stdlib.h>

long long logica_condicional_var6() {
  long long* state = malloc(sizeof(long long));
  if (!state) return 0;

  *state = 1;
  for (long long i = 1; i <= 2800000; ++i) {
    if ((*state) % ((i % 10) + 1) == 0) {
      *state = (*state) / ((i % 10) + 1) + i;
    } else if ((*state) % ((i % 7) + 2) == 1) {
      *state = (*state) * ((i % 5) + 1) - i;
    } else {
      *state = (*state) + ((*state) % 100) - (i % 100);
    }
    if (*state == 0) *state = i;  // Avoid stagnation
    if (*state > 5000000000LL) *state = (*state) % 100000000LL + 1;
    if (*state < -5000000000LL) *state = (*state) % 100000000LL - 1;
  }

  long long result = (*state) % 256;
  free(state);
  return result;
}

int main() {
  logica_condicional_var6();
  return 0;
}
