bool cronometroA(long valor_inicial) {
  resetTimeA=true;
  long tempo_corrido = millis() - valor_inicial;  
  if (tempo_corrido > VOLTAGETIMERCHECK){
    resetTimeA=false;
    return true;
  }
  return false;
}


float mili_p_min(long int entrada) {
  float saida = entrada / 60000.00;  
  return saida;
}

long int min_p_mili(int entrada) {
  long int saida = entrada * 60000;
  return saida;
}
