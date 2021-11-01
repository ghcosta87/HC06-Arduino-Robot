void runToForward() {
  if (wheelsFwdStoped()) {
    rightSpeedFWD = MOTORSTART_POS;
    leftSpeedFWD = MOTORSTART_POS;
  } else {
    rightSpeedFWD += acelerationStep;
    leftSpeedFWD += acelerationStep;
  }
  if (analogOverLimit(rightSpeedFWD))rightSpeedFWD = 255;
  if (analogOverLimit(leftSpeedFWD))leftSpeedFWD = 255;
}
void stopFromForward() {
  if (wheelsFwdRunning()) {
    rightSpeedFWD -= acelerationStep;
    leftSpeedFWD -= acelerationStep;
    if (analogOverLimit(rightSpeedFWD))rightSpeedFWD = 0;
    if (analogOverLimit(leftSpeedFWD))leftSpeedFWD = 0;
  }
}

void runToBackward() {
  if (wheelsBwdStoped()) {
    rightSpeedBWD = MOTORSTART_POS;
    leftSpeedBWD = MOTORSTART_POS;
  } else {
    rightSpeedBWD += acelerationStep;
    leftSpeedBWD += acelerationStep;
  }
  if (analogOverLimit(rightSpeedBWD))rightSpeedBWD = 255;
  if (analogOverLimit(leftSpeedBWD))leftSpeedBWD = 255;
}

void stopFromBackward() {
  if (wheelsBwdRunning()) {
    rightSpeedBWD -= acelerationStep;
    leftSpeedBWD -= acelerationStep;
    if (analogOverLimit(rightSpeedBWD))rightSpeedBWD = 0;
    if (analogOverLimit(leftSpeedBWD))leftSpeedBWD = 0;
  }
}
