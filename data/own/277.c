// 277.c
// Lógica condicional en bucle (variación 8)
int main() {
  volatile int x = 0, y = 0, z = 0;
  long long accumulator = 0;
  for (long long i = 0; i < 3200000; ++i) {
    x = (int)(i % 100) - 50;
    y = (int)((i / 100) % 100) - 50;
    z = (int)((i / 10000) % 100) - 50;
    if (x > 0 && y > 0 && z > 0)
      accumulator += (x + y + z);
    else if (x < 0 && y < 0 && z < 0)
      accumulator += (x * y * z);
    else
      accumulator -= (x - y - z);
    if (accumulator > 100000000) accumulator = accumulator % 100000000;
    if (accumulator < -100000000) accumulator = accumulator % 100000000;
  }
  return (int)(accumulator % 256);
}
