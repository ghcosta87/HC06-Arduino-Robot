void acelerate(char direction) {
  if (releaseBreakes) {
    switch (direction) {
      case FORWARD:
        movement[0] = true;
        movement[1] = false;
        movement[2] = true;
        if (rightSpeedBWD > 0 && leftSpeedBWD > 0) { // ||
          if (rightSpeedBWD != 0)rightSpeedBWD -= acelerationStep;
          if (leftSpeedBWD != 0)leftSpeedBWD -= acelerationStep;
        } else {
          if (rightSpeedFWD < 255)rightSpeedFWD += acelerationStep;
          if (leftSpeedFWD < 255)leftSpeedFWD += acelerationStep;
        }
        break;
      case BACKWARD:
        movement[0] = false;
        movement[1] = true;
        movement[2] = false;
        if (rightSpeedFWD > 0 && leftSpeedFWD > 0) { // ||
          if (rightSpeedFWD != 0)rightSpeedFWD -= acelerationStep;
          if (leftSpeedFWD != 0)leftSpeedFWD -= acelerationStep;
        } else {
          if (rightSpeedBWD < 255)rightSpeedBWD += acelerationStep;
          if (leftSpeedBWD < 255)leftSpeedBWD += acelerationStep;
        }
        break;
      case FRONTNEUTRAL:
        movement[0] = false;
        movement[1] = false;
        if (rightSpeedBWD != 0)rightSpeedBWD -= acelerationStep;
        if (leftSpeedBWD != 0)leftSpeedBWD -= acelerationStep;
        if (rightSpeedFWD != 0)rightSpeedFWD -= acelerationStep;
        if (leftSpeedFWD != 0)leftSpeedFWD -= acelerationStep;
        break;
      case LEFTSIDE:
        if (movement[0]) { //  foward
          if (leftSpeedFWD != 0)leftSpeedFWD -= acelerationStep;
          if (rightSpeedFWD < 255)rightSpeedFWD += acelerationStep;
        } else if (movement[1]) { //  backward
          if (leftSpeedBWD != 0)leftSpeedBWD -= acelerationStep;
          if (rightSpeedBWD < 255)rightSpeedBWD += acelerationStep;
        } else if (movement[2]) {
          if (leftSpeedFWD != 0)leftSpeedFWD -= acelerationStep;
        } else if (!movement[2]) {
          if (leftSpeedBWD != 0)leftSpeedBWD -= acelerationStep;
        }
        break;
      case RIGHTSIDE:
        if (movement[0]) { //  foward
          if (rightSpeedFWD != 0)rightSpeedFWD -= acelerationStep;
          if (leftSpeedFWD < 255)leftSpeedFWD += acelerationStep;
        } else if (movement[1]) { //  backward
          if (rightSpeedBWD != 0)rightSpeedBWD -= acelerationStep;
          if (leftSpeedBWD < 255)leftSpeedBWD += acelerationStep;
        } else if (movement[2]) {
          if (rightSpeedFWD != 0)rightSpeedFWD -= acelerationStep;
        } else if (!movement[2]) {
          if (rightSpeedBWD != 0)rightSpeedBWD -= acelerationStep;
        }
        break;
      case SIDENEUTRAL:
        if (movement[0]) { //  foward
          if (rightSpeedFWD < 255)rightSpeedFWD += acelerationStep;
          if (leftSpeedFWD < 255)leftSpeedFWD += acelerationStep;
        } else if (movement[1]) { //  backward
          if (rightSpeedBWD < 255)rightSpeedBWD += acelerationStep;
          if (leftSpeedBWD < 255)leftSpeedBWD += acelerationStep;
        } else {
          if (rightSpeedBWD != 0)rightSpeedBWD -= acelerationStep;
          if (leftSpeedBWD != 0)leftSpeedBWD -= acelerationStep;
          if (rightSpeedFWD != 0)rightSpeedFWD -= acelerationStep;
          if (leftSpeedFWD != 0)leftSpeedFWD -= acelerationStep;
        }
        break;
      case STOP:
        breakNow();
        releaseBreakes = false;
        return 0;
    }
    if (rightSpeedFWD != 0 || leftSpeedFWD != 0) {
      rightSpeedBWD = 0;
      leftSpeedBWD = 0;
    }
    if (rightSpeedBWD != 0 || leftSpeedBWD != 0) {
      rightSpeedFWD = 0;
      leftSpeedFWD = 0;
    }
    walk(rightSpeedFWD, rightSpeedBWD, leftSpeedFWD, leftSpeedBWD);
  } else {
    if (direction == STOPRELEASED)releaseBreakes = true;
  }
}
void walk(int speedRF, int speedRB, int speedLF, int speedLB) {
  if (DEBUG)Serial.println((String)commandReceived + " > " + (String)speedRF + " ~ " + (String)speedRB + " ~ " + (String)speedLF + " ~ " + (String)speedLB + " ~ " + (String)currentVoltage);
  analogWrite(RIGHTMOTOR_F, speedRF);
  analogWrite(RIGHTMOTOR_B, speedRB);
  analogWrite(LEFTMOTOR_F, speedLF);
  analogWrite(LEFTMOTOR_B, speedLB);
}

void acelerator() {

}

void sendData() {

}

void breakNow() {
  rightSpeedBWD = 0;
  leftSpeedBWD = 0;
  rightSpeedFWD = 0;
  leftSpeedFWD = 0;
  walk(0, 0, 0, 0);
}
