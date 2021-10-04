#include <SoftwareSerial.h>
#include "definitions.h"
#include "globalVariables.h"

SoftwareSerial btSerial(RX, TX);

void setup() {
  // SETUP.ino
  portsSetup();

  // SETUP.ino
  comSetup();
}

void loop() {
  //  bleSerialCom.ino
  serialTalk();

  //  carControl.ino
  acelerate(commandReceived);

  //  carAuxiliars.ino
  voltageCheck();
}
