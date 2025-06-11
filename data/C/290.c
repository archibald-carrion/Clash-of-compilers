// 290.c
// Lógica condicional en bucle (variación 11)
// Simple particle movement simulation with boundary checks
#include <stdlib.h>

long long logica_condicional_var11() {
  float* pos_x = malloc(sizeof(float));
  float* pos_y = malloc(sizeof(float));
  float* vel_x = malloc(sizeof(float));
  float* vel_y = malloc(sizeof(float));
  float* min_bound = malloc(sizeof(float));
  float* max_bound = malloc(sizeof(float));
  long long* score = malloc(sizeof(long long));

  if (!pos_x || !pos_y || !vel_x || !vel_y || !min_bound || !max_bound ||
      !score) {
    free(pos_x);
    free(pos_y);
    free(vel_x);
    free(vel_y);
    free(min_bound);
    free(max_bound);
    free(score);
    return 0;
  }

  *pos_x = 0.0f;
  *pos_y = 0.0f;
  *vel_x = 0.1f;
  *vel_y = 0.05f;
  *min_bound = -100.0f;
  *max_bound = 100.0f;
  *score = 0;

  for (long long i = 0; i < 1500000; ++i) {
    *pos_x += (*vel_x) * ((i % 10) + 1);
    *pos_y += (*vel_y) * ((i % 10) + 1);

    if (*pos_x > *max_bound) {
      *vel_x = -(*vel_x);
      (*score)++;
      *pos_x = *max_bound;
    } else if (*pos_x < *min_bound) {
      *vel_x = -(*vel_x);
      (*score)++;
      *pos_x = *min_bound;
    }
    if (*pos_y > *max_bound) {
      *vel_y = -(*vel_y);
      (*score)--;
      *pos_y = *max_bound;
    } else if (*pos_y < *min_bound) {
      *vel_y = -(*vel_y);
      (*score)--;
      *pos_y = *min_bound;
    }

    if (i % 1000 == 0) {  // Change velocity direction slightly
      float temp_vx = *vel_x;
      *vel_x = (*vel_x) * 0.8f - (*vel_y) * 0.6f;
      *vel_y = temp_vx * 0.6f + (*vel_y) * 0.8f;
      // Normalize to prevent explosion/decay of speed, roughly
      float speed = (*vel_x) * (*vel_x) + (*vel_y) * (*vel_y);
      if (speed > 0.0226f ||
          speed < 0.0224f && speed != 0) {  // if speed not near 0.15
        *vel_x = 0.1f;
        *vel_y = 0.05f;  // reset
      }
    }
  }

  long long result = (*score) % 256;
  free(pos_x);
  free(pos_y);
  free(vel_x);
  free(vel_y);
  free(min_bound);
  free(max_bound);
  free(score);
  return result;
}

int main() {
  logica_condicional_var11();
  return 0;
}
