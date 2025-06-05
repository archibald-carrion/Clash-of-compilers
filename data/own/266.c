// 266.c
// Lógica condicional en bucle (variación 7)
int main() {
  volatile float x = 0.5f, y = 0.5f, z = 0.5f;
  int count = 0;
  for (long long i = 0; i < 1000000; ++i) {
    float next_x =
        y * ((i % 100) / 50.0f - 1.0f) + z * ((i % 80) / 40.0f - 1.0f);
    float next_y =
        x * ((i % 120) / 60.0f - 1.0f) + z * ((i % 60) / 30.0f - 1.0f);
    float next_z =
        x * ((i % 140) / 70.0f - 1.0f) + y * ((i % 40) / 20.0f - 1.0f);
    x = next_x > 1.0f ? 1.0f : (next_x < -1.0f ? -1.0f : next_x);
    y = next_y > 1.0f ? 1.0f : (next_y < -1.0f ? -1.0f : next_y);
    z = next_z > 1.0f ? 1.0f : (next_z < -1.0f ? -1.0f : next_z);
    if (x * x + y * y + z * z < 0.1f)
      count++;
    else
      count--;
  }
  return count % 256;
}
