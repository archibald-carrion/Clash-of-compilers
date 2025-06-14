// 278.c
// Lógica condicional en bucle (variación 9)
// Simulating state machine transitions
#include <stdlib.h>

long long logica_condicional_var9() {
  int* state = malloc(sizeof(int));
  long long* counter = malloc(sizeof(long long));

  if (!state || !counter) {
    free(state);
    free(counter);
    return 0;
  }

  *state = 0;  // 0: IDLE, 1: PROC_A, 2: PROC_B, 3: WAIT
  *counter = 0;

  for (long long i = 0; i < 2500000; ++i) {
    (*counter)++;
    int event = (int)(i % 10);
    switch (*state) {
      case 0:  // IDLE
        if (event < 3)
          *state = 1;
        else if (event < 6)
          *state = 2;
        else
          *state = 3;
        break;
      case 1:  // PROC_A
        *counter += i % 100;
        if (event % 2 == 0)
          *state = 0;
        else
          *state = 3;
        break;
      case 2:  // PROC_B
        *counter -= i % 50;
        if (event > 5)
          *state = 0;
        else
          *state = 3;
        break;
      case 3:  // WAIT
        if (event == 0 || event == 9)
          *state = 0;
        else if (event < 5)
          *state = 1;
        else
          *state = 2;
        break;
    }
  }

  long long result = ((*counter) + (*state)) % 256;
  free(state);
  free(counter);
  return result;
}

int main() {
  logica_condicional_var9();
  return 0;
}
