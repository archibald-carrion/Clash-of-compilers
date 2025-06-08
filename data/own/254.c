// 254.c
// Lógica condicional en bucle (variación 5)
#include <stdlib.h>

int logica_condicional_var5() {
  double* val = malloc(sizeof(double));
  if (!val) return 0;

  *val = 1.0;
  for (long long i = 1; i <= 2000000; ++i) {
    if ((long long)(*val) % 2 == 0 && i % 2 == 0) {
      *val += (double)i / ((*val > 0 ? *val : 1.0) * 0.5);
    } else {
      *val -= (double)i / ((*val < 0 ? *val : -1.0) * 0.5);
    }
    if (*val > 1e12) *val = 1.0;
    if (*val < -1e12) *val = -1.0;
    if (*val == 0.0)
      *val = i;  // Avoid division by zero if val becomes exactly 0
  }

  int result = (int)((long long)(*val) % 256);
  free(val);
  return result;
}

int main() {
  logica_condicional_var5();
  return 0;
}
