
String checkSonar() {
  int distance = sonar.ping_cm();
  if (distance < 15)blockedPath();
  else pathBlocked = false;
  return (String)distance;
}

String voltageCheck() {
  float currentVoltage = mapf(analogRead(VOLTAGEMONITOR), 0, 993, 0, 5);
  if (currentVoltage < 4.6)
    return BATT0;
  if (currentVoltage > 4.6 && currentVoltage < 4.7)
    return  BATT25;
  if (currentVoltage > 4.7 && currentVoltage < 4.8)
    return BATT50;
  if (currentVoltage > 4.8 && currentVoltage < 4.9)
    return  BATT100;
  if (currentVoltage > 4.9)
    return  BATT100;
  return "0";
}

String bleConnected() {
  return (String)digitalRead(CONNECTIVITY);
}

String sendDirection(int setArrow) {
  if (pathBlocked)return"⊗";
  switch (setArrow) {
    case _STOPPED: return "x";
      break;
    case _FORWARD: return "↥";
      break;
    case _FORWARD_LEFT: return "↖";
      break;
    case _FORWARD_RIGHT: return "↗";
      break;
    case _BACKWARD: return "↧";
      break;
    case _BACKWARD_LEFT: return "↙";
      break;
    case _BACKWARD_RIGHT: return "↘";
      break;
  }
}
