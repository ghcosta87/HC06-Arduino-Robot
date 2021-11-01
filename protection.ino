void blockedPath() {
  pathBlocked = true;
  switch (currentDirection) {
    case _FORWARD:
    case _FORWARD_LEFT:
    case _FORWARD_RIGHT:
      breakNow();
      break;
  }
}
