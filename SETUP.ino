void portsSetup() {
  pinMode(RIGHTMOTOR_F, OUTPUT);
  pinMode(RIGHTMOTOR_B, OUTPUT);
  pinMode(LEFTMOTOR_F, OUTPUT);
  pinMode(LEFTMOTOR_B, OUTPUT);
}

void comSetup() {  
  btSerial.begin(9600);
  Serial.begin(9600);
}
