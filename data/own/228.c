// 228.c
// Manipulación de array (variación 3)
#define ARRAY_SIZE_228 256
int main() {
  volatile int matrix[ARRAY_SIZE_228][ARRAY_SIZE_228];
  long long suma_diag = 0;
  for (int iter = 0; iter < 10;
       ++iter) {  // Fewer iterations due to N*N complexity
    for (int i = 0; i < ARRAY_SIZE_228; ++i) {
      for (int j = 0; j < ARRAY_SIZE_228; ++j) {
        matrix[i][j] = (i * j + iter) % 1000;
      }
    }
    for (int i = 0; i < ARRAY_SIZE_228; ++i) {
      suma_diag += matrix[i][i];
    }
  }
  return (int)(suma_diag % 256);
}
