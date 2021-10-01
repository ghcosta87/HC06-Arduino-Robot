int blueLed = 10; 
int yellowLed = 11;
int redLed = 12;
int greenLed = 13;
int button =4;

void readTest(char input){
  if (input == 'f') {}
  if (input == 'F')ledTest(0b0001);
  if (input == 'B')ledTest(0b0010);
  if (input == 'R')ledTest(0b0100);
  if (input == 'L')ledTest(0b1000);
  if (input == 'N')ledTest(0b0000);
  if (input == 'n')ledTest(0b0000);
}

void ledTest(int ledSequence) {
  switch (ledSequence) {
    case 0b0000:
//    delay(2000);
    digitalWrite(blueLed,LOW);
    digitalWrite(yellowLed,LOW);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
      break;
    case 0b0001:
    digitalWrite(blueLed,HIGH);
    digitalWrite(yellowLed,LOW);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
      break;
    case 0b0010:
    digitalWrite(blueLed,LOW);
    digitalWrite(yellowLed,HIGH);
    digitalWrite(redLed,LOW); 
    digitalWrite(greenLed,LOW);
      break;
    case 0b0100:
    digitalWrite(blueLed,LOW);
    digitalWrite(yellowLed,LOW);
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
      break;
    case 0b1000:
    digitalWrite(blueLed,LOW);
    digitalWrite(yellowLed,LOW);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
      break;
  }
}

void buttonPressed(){
  if (!digitalRead(button)){
    btSerial.write("b4");
    Serial.println("botao pressionado");
  }
}

void ledSetup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
