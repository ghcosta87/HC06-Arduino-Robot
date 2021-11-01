void turnToRight() {
  switch (currentDirection) {
    case _FORWARD:
    case _FORWARD_RIGHT:
      currentDirection = _FORWARD_RIGHT;
      lastDirection = _FORWARD;

      leftSpeedFWD += acelerationStep;
      if (analogOverLimit(leftSpeedFWD))leftSpeedFWD = 255;

      rightSpeedFWD -= acelerationStep;
      if (analogOverLimit(rightSpeedFWD))rightSpeedFWD = 0;

      break;

    case _BACKWARD:
    case _BACKWARD_RIGHT:
      currentDirection = _BACKWARD_RIGHT;
      lastDirection = _BACKWARD;

      leftSpeedBWD += acelerationStep;
      if (analogOverLimit(leftSpeedBWD))leftSpeedBWD = 255;

      rightSpeedBWD -= acelerationStep;
      if (analogOverLimit(rightSpeedBWD))rightSpeedBWD = 0;

      break;
  }
}
