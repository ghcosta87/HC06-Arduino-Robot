bool wheelsFwdStoped() {
  if (rightSpeedFWD == 0 && leftSpeedFWD == 0 )return true;
  return false;
}
bool wheelsFwdRunning() {
  if (rightSpeedFWD > 0 && leftSpeedFWD > 0 )return true;
  return false;
}
bool wheelsFwdMaxSpeed() {
  if (rightSpeedFWD == 255 && leftSpeedFWD == 255)return true;
  return false;
}


bool wheelsBwdStoped() {
  if (rightSpeedBWD == 0 && leftSpeedBWD == 0 )return true;
  return false;
}
bool wheelsBwdRunning() {
  if (rightSpeedBWD > 0 && leftSpeedBWD > 0 )return true;
  return false;
}
bool wheelsBwdMaxSpeed() {
  if (rightSpeedBWD == 255 && leftSpeedBWD == 255)return true;
  return false;
}

void forwardAction() {
  lastDirection = currentDirection;
  currentDirection = _FORWARD;

  switch (lastDirection) {
    case _STOPPED:
    case _FORWARD:
      if (!wheelsBwdRunning()) {
        if (!wheelsFwdMaxSpeed()) {
          runToForward();
        }
      } else {
        stopFromBackward();
      }
      break;
    case _FORWARD_LEFT:
    case _FORWARD_RIGHT:
      runToForward();
      break;
  }
}

void backwardAction() {
  lastDirection = currentDirection;
  currentDirection = _BACKWARD;

  switch (lastDirection) {
    case _STOPPED:
    case _BACKWARD:
      currentDirection = _BACKWARD;
      if (!wheelsFwdRunning()) {
        if (!wheelsBwdMaxSpeed()) {
          runToBackward();
        }
      } else {
        stopFromForward();
      }
      break;
    case _FORWARD_LEFT:
    case _FORWARD_RIGHT:
      runToBackward();
      break;
  }
}
