// 280.c
// Operaciones mixtas (variación 9)
// Fibonacci sequence generation with some twists
int main() {
  volatile unsigned long long fib_a = 0, fib_b = 1, temp_fib;
  volatile unsigned int bit_mangler = 0xDEADBEEF;
  long long sum_check = 0;

  for (long long i = 0; i < 90;
       ++i) {  // Fibonacci grows fast, limit iterations
    temp_fib = fib_a + fib_b;
    fib_a = fib_b;
    fib_b = temp_fib;

    if (i % 3 == 0)
      bit_mangler ^= (unsigned int)(fib_b & 0xFFFFFFFF);
    else
      bit_mangler =
          (bit_mangler >> 1) + (unsigned int)((fib_a >> 32) & 0xFFFFFFFF);

    sum_check += (long long)(bit_mangler % 1000) - 500;
  }
  return (int)((fib_b + bit_mangler + sum_check) % 256);
}
