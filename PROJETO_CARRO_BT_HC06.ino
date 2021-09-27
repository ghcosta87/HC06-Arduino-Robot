#include <SoftwareSerial.h>
#include "Definicions.h"

SoftwareSerial btSerial(RX, TX);

char commandReceived;
char commandSent;

float currentVoltage=0;

int rightSpeedFWD = 0;
int leftSpeedFWD = 0;
int rightSpeedBWD = 0;
int leftSpeedBWD = 0;

int acelerationStep = 5;

void setup() {
  // SETUP.ino
  portsSetup();

  // SETUP.ino
  comSetup();

  ledSetup();
}

void loop() {
  if (btSerial.available()) {
    commandReceived = btSerial.read();
    if (DEBUG)Serial.println("Comando recebido > " + commandReceived);
  }

  if (Serial.available()) {
    // input = Serial.readString();
    commandSent = Serial.read();
    if (DEBUG)Serial.println("Comando enviado > " + commandSent);
  }

  acelerate(commandReceived);

  voltageCheck();
}
