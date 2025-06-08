// 274.c
// Operaciones bitwise en un bucle (variación 11)
// Simulating a Linear Feedback Shift Register (LFSR)
#include <stdlib.h>

int operaciones_bitwise_var11() {
  unsigned long long* lfsr =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  unsigned long long* period =
      (unsigned long long*)malloc(sizeof(unsigned long long));
  if (lfsr == NULL || period == NULL) {
    free(lfsr);
    free(period);
    return -1;  // Error en la asignación de memoria
  }

  *lfsr = 0xACE1uLL;  // Non-zero start
  *period = 0;
  for (long long i = 0; i < 1500000; ++i) {
    unsigned lsb = *lfsr & 1uLL;  // Get LSB
    *lfsr >>= 1;                  // Shift right
    if (lsb) {                   // If LSB is 1, apply XOR mask
      *lfsr ^= 0xB400uLL;        // Taps for 16-bit, common for PRNG
    }
    (*period)++;  // Not really period, just a counter for work
  }

  int resultado = (int)((*lfsr + *period) % 256);
  free(lfsr);
  free(period);
  return resultado;
}

int main() {
  operaciones_bitwise_var11();
  return 0;
}
