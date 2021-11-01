void acelerate(char direction) {
  if (releaseBreakes)  {
    switch (direction)    {
      case FORWARD:
        if (!pathBlocked)forwardAction();
        break;
      case BACKWARD:
        backwardAction();
        break;
      case FRONTNEUTRAL:
        switch (lastDirection ) {
          case _FORWARD:
            stopFromForward();
            if (wheelsFwdStoped()) currentDirection = _STOPPED;
            break;
          case _FORWARD_LEFT:
          case _FORWARD_RIGHT:
            break;
          case _BACKWARD:
            stopFromBackward();
            if (wheelsBwdStoped()) currentDirection = _STOPPED;
            break;
          case _BACKWARD_LEFT:
          case _BACKWARD_RIGHT:
            break;
        }
        break;
      case LEFTSIDE:
        if (!pathBlocked)turnToLeft();
        break;
      case RIGHTSIDE:
        if (!pathBlocked)turnToRight();
        break;
      case SIDENEUTRAL:
        switch (lastDirection ) {
          case _FORWARD:
            if (!pathBlocked)forwardAction();
            break;
          case _FORWARD_LEFT:
          case _FORWARD_RIGHT:
            if (keepTurning)
              if (!pathBlocked)forwardAction();
            break;
          case _BACKWARD:
          case _BACKWARD_LEFT:
          case _BACKWARD_RIGHT:
            if (keepTurning)
              backwardAction();
            break;
        }
        break;
      case STOP:
        keepTurning = true;
        breakNow();
        releaseBreakes = false;
        return 0;
    }
    walk(rightSpeedFWD, rightSpeedBWD, leftSpeedFWD, leftSpeedBWD);
  }
  if (direction == STOPRELEASED)releaseBreakes = true;
}

void walk(int speedRF, int speedRB, int speedLF, int speedLB) {
  if (DEBUG)Serial.println((String)commandReceived + " > " + (String)speedRF + " ~ " + (String)speedRB + " ~ " + (String)speedLF + " ~ " + (String)speedLB + " ~ " + (String)currentDirection);
  analogWrite(RIGHTMOTOR_F, speedRF);
  analogWrite(RIGHTMOTOR_B, speedRB);
  analogWrite(LEFTMOTOR_F, speedLF);
  analogWrite(LEFTMOTOR_B, speedLB);
}

void breakNow() {
  rightSpeedBWD = 0;
  leftSpeedBWD = 0;
  rightSpeedFWD = 0;
  leftSpeedFWD = 0;
  walk(0, 0, 0, 0);
}
