bool resetTimeA = false;

//float voltage= sensorValue * (5.0 / 1023.0);
void voltageCheck() {
  currentVoltage = mapf(analogRead(VOLTAGEMONITOR), 0, 1023, 0, 5);
  long setTimer;
  if (!resetTimeA)setTimer = millis();
  if (cronometroA(setTimer)) {
    if (DEBUG)Serial.println(" >>>>>>>>>>>> SENDING DATA NOW ! <<<<<<<<<<<<<");
    if (currentVoltage < 4.6)btSerial.write(BATT0);
    if (currentVoltage > 4.6 && currentVoltage < 4.7)btSerial.write(BATT25);
    if (currentVoltage > 4.7 && currentVoltage < 4.8)btSerial.write(BATT50);
    if (currentVoltage > 4.8 && currentVoltage < 4.9)btSerial.write(BATT100);
    if (currentVoltage > 4.9)btSerial.write(BATT100);    
  }
}

void bleConnected() {
  //  if (digitalRead(CONNECTIVITY))if (DEBUG)Serial.println(">>  SEM CONEXÃO <<");
}

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
