// 269.c
// Suma/resta aritmética en un bucle (variación 11)
#include <stdlib.h>

long long suma_resta_var11() {
  long long* suma_total = malloc(sizeof(long long));
  long long* current_val = malloc(sizeof(long long));

  if (!suma_total || !current_val) {
    free(suma_total);
    free(current_val);
    return 0;
  }

  *suma_total = 0;
  *current_val = 1;

  for (long long i = 1; i <= 1300000; ++i) {
    *current_val += i;
    if (i % 2 == 0)
      *suma_total += *current_val;
    else
      *suma_total -= *current_val;
    if (*suma_total > 1000000000000LL) *suma_total = *current_val;
    if (*suma_total < -1000000000000LL) *suma_total = -(*current_val);
  }

  long long result = (*suma_total) % 256;
  free(suma_total);
  free(current_val);
  return result;
}

int main() {
  suma_resta_var11();
  return 0;
}
