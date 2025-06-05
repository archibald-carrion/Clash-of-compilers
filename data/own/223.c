// 223.c
// Multiplicación/división en un bucle (variación 2)
int main() {
  volatile double producto_d = 1.0;
  for (int i = 1; i <= 60; ++i) {  // Loop count adjusted for double precision
    producto_d *= (double)i * 1.000001;
  }
  return (int)((long long)producto_d % 256);
}
