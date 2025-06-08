// 290.c
// Lógica condicional en bucle (variación 11)
// Simple particle movement simulation with boundary checks
int main() {
  volatile float pos_x = 0.0f, pos_y = 0.0f;
  volatile float vel_x = 0.1f, vel_y = 0.05f;
  float min_bound = -100.0f, max_bound = 100.0f;
  long long score = 0;

  for (long long i = 0; i < 1500000; ++i) {
    pos_x += vel_x * ((i % 10) + 1);
    pos_y += vel_y * ((i % 10) + 1);

    if (pos_x > max_bound) {
      vel_x = -vel_x;
      score++;
      pos_x = max_bound;
    } else if (pos_x < min_bound) {
      vel_x = -vel_x;
      score++;
      pos_x = min_bound;
    }
    if (pos_y > max_bound) {
      vel_y = -vel_y;
      score--;
      pos_y = max_bound;
    } else if (pos_y < min_bound) {
      vel_y = -vel_y;
      score--;
      pos_y = min_bound;
    }

    if (i % 1000 == 0) {  // Change velocity direction slightly
      float temp_vx = vel_x;
      vel_x = vel_x * 0.8f - vel_y * 0.6f;
      vel_y = temp_vx * 0.6f + vel_y * 0.8f;
      // Normalize to prevent explosion/decay of speed, roughly
      float speed = vel_x * vel_x + vel_y * vel_y;
      if (speed > 0.0226f ||
          speed < 0.0224f && speed != 0) {  // if speed not near 0.15
        vel_x = 0.1f;
        vel_y = 0.05f;  // reset
      }
    }
  }
  return (int)(score % 256);
}
