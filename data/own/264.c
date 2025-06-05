// 264.c
// Manipulación de array (variación 10)
#define ARRAY_SIZE_264 192
int main() {
  volatile double array3d[ARRAY_SIZE_264][4][2];  // Small 3D array
  double total_sum = 0.0;
  for (int iter = 0; iter < 50; ++iter) {
    for (int i = 0; i < ARRAY_SIZE_264; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 2; ++k) {
          array3d[i][j][k] = (double)(i * 0.1 + j * 0.5 + k * 0.25 + iter);
        }
      }
    }
    for (int i = 0; i < ARRAY_SIZE_264; i += 2) {
      for (int j = 0; j < 4; j += 2) {
        for (int k = 0; k < 2; ++k) {
          total_sum += array3d[i][j][k];
        }
      }
    }
  }
  return (int)((long long)total_sum % 256);
}
