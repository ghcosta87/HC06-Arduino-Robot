void serialTalk() {
  if (btSerial.available()) {
    commandReceived = btSerial.read();
    if (DEBUG)Serial.println("Comando recebido > " + commandReceived);
  }

  if (Serial.available()) {
    commandSent = Serial.read();
    if (DEBUG)Serial.println("Comando enviado > " + commandSent);
  }
}
