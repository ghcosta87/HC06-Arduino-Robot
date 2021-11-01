#include <SoftwareSerial.h>
#include <NewPing.h>
#include <Servo.h>

#include "definitions.h"
#include "globalVariables.h"

SoftwareSerial btSerial(RX, TX);
NewPing sonar(SONAR_TRIGGER, SONAR_ECHO, 200);

void setup() {
  portsSetup(); // SETUP.ino

  comSetup(); // SETUP.ino
}

void loop() {
  serialTalk(); //  bleSerialCom.ino

  acelerate(commandReceived); //  carControl.ino

  voltageCheck(); //  carAuxiliars.ino

  checkSonar(); //  carAuxiliars.ino
  
  sendData();
}
