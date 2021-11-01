bool resetTimeA = false;
bool resetTimeB = false;

bool cronometro(long valor_inicial, char timerSelection) {
  long tempo_corrido = millis() - valor_inicial;
  switch (timerSelection) {
    case 'A':
      resetTimeA = true;
      if (tempo_corrido > SENDDATA_INTERVAL) {
        resetTimeA = false;
        return true;
      }
      break;
    case 'B': resetTimeB = true;
      resetTimeB = true;
      if (tempo_corrido > VOLTAGETIMERCHECK) {
        resetTimeB = false;
        return true;
      }
      break;
  }
  return false;
}
