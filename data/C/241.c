// 241.c
// Lógica condicional en bucle (variación 3)
#include <stdlib.h>

int logica_condicional_var3() {
  long long* val = (long long*)malloc(sizeof(long long));
  if (val == NULL) {
    return -1;  // Error en la asignación de memoria
  }

  *val = 5555;
  for (long long i = 1; i <= 3500000; ++i) {
    switch (i % 4) {
      case 0:
        *val += i / 2;
        break;
      case 1:
        *val -= i * 2;
        break;
      case 2:
        if (*val != 0) *val /= ((i % 3) + 1);
        break;
      case 3:
        *val *= (i % 5) + 1;
        break;
    }
    if (*val > 100000000000LL) *val = i;
    if (*val < -100000000000LL) *val = -i;
  }

  int resultado = (int)(*val % 256);
  free(val);
  return resultado;
}

int main() {
  logica_condicional_var3();
  return 0;
}
