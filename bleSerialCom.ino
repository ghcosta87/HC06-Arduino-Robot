void serialTalk() {
  if (btSerial.available())  {
    commandReceived = btSerial.read();
  }

  if (Serial.available()) {
    commandSent = Serial.read();
  }
}

void sendData() {
  if (!resetTimeA)setTimer = millis();
  if (cronometro(setTimer,'A')) {
    String bleSonar = "d " + checkSonar();
    String bleDirection = " a " + sendDirection(currentDirection);
    String bleVoltage = " v " + voltageCheck();
    String bleStatus = " b" + bleConnected();
    String convert = bleSonar + bleDirection + bleVoltage + bleStatus;
    const char *out = convert.c_str();
    Serial.println("Sendind data >>> " + (String)out);
    writeToBle(out);
  }
}

void writeToBle(const char *input) {
  btSerial.write(input);
}
