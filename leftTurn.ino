void turnToLeft() {
  switch (currentDirection) {
    case _FORWARD:
    case _FORWARD_LEFT:
      currentDirection = _FORWARD_LEFT;
      lastDirection = _FORWARD;

      rightSpeedFWD += acelerationStep;
      if (analogOverLimit(rightSpeedFWD))rightSpeedFWD = 255;

      leftSpeedFWD -= acelerationStep;
      if (analogOverLimit(leftSpeedFWD))leftSpeedFWD = 0;

      break;
      
    case _BACKWARD:
    case _BACKWARD_LEFT:
      currentDirection = _BACKWARD_LEFT;
      lastDirection = _BACKWARD;

      rightSpeedBWD += acelerationStep;
      if (analogOverLimit(rightSpeedBWD))rightSpeedBWD = 255;

      leftSpeedBWD -= acelerationStep;
      if (analogOverLimit(leftSpeedBWD))leftSpeedBWD = 0;
      break;
  }
}
