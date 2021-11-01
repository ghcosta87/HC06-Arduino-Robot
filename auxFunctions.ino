float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float mili_p_min(long int entrada) {
  float saida = entrada / 60000.00;
  return saida;
}

long int min_p_mili(int entrada) {
  long int saida = entrada * 60000;
  return saida;
}

bool analogOverLimit(int input) {
  if (input < 0 || input > 255) return true;
  return false;
}
