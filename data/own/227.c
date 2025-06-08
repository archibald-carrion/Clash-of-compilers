// 227.c
// Manipulación de array (variación 2)
#include <stdlib.h>

#define ARRAY_SIZE_227 2048

int manipulacion_array_char() {
  char* array = (char*)malloc(ARRAY_SIZE_227 * sizeof(char));
  long long* suma_ascii = (long long*)malloc(sizeof(long long));

  if (array == NULL || suma_ascii == NULL) {
    free(array);
    free(suma_ascii);
    return -1;  // Error en la asignación de memoria
  }

  *suma_ascii = 0;
  for (int k = 0; k < 300; ++k) {
    for (int i = 0; i < ARRAY_SIZE_227; ++i) {
      array[i] = (char)((i * k + 65) % 26 + 'A');  // Store uppercase letters
    }
    for (int i = 0; i < ARRAY_SIZE_227; ++i) {
      *suma_ascii += array[i];
    }
  }

  int resultado = (int)(*suma_ascii % 256);
  free(array);
  free(suma_ascii);
  return resultado;
}

int main() {
  manipulacion_array_char();
  return 0;
}
