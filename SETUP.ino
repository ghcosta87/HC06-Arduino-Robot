void portsSetup() {
  TCCR2B = TCCR2B & B11111000 | B00000001; // D3 e D11
  TCCR1B = TCCR1B & B11111000 | B00000001; // D9 e D10
  //  TCCR0B = TCCR0B & B11111000 | B00000001; // D5 e D6

  pinMode(RIGHTMOTOR_F, OUTPUT);
  pinMode(RIGHTMOTOR_B, OUTPUT);
  pinMode(LEFTMOTOR_F, OUTPUT);
  pinMode(LEFTMOTOR_B, OUTPUT);
}

void comSetup() {
  btSerial.begin(9600);
  Serial.begin(9600);
}
