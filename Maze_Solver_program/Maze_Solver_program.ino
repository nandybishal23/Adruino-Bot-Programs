
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void moveRobot(String motion)
{
  if (motion == "Forward")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    Serial.print("Forward");
  }
  if (motion == "Backward")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    Serial.print("Backward");
  }
  if (motion == "Left")
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    Serial.print("Left");
  }
  if (motion == "Right")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    Serial.print("Right");
  }
  if (motion == "Stop")
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    Serial.print("Stop");
  }
}
void turnleft() {
  Serial.println("turnleft");
  int M_temp = 1;
  while (M_temp != 0) {
    moveRobot("Left");
    delay(100);
    moveRobot("Stop");
    delay(100);

    M_temp = digitalRead(3);
  }
}
void turnright() {
  Serial.println("turnright");
  int L_temp = 1;
  while (L_temp != 0) {
    moveRobot("right");
    delay(100);
    moveRobot("Stop");
    delay(100);

    L_temp = digitalRead(2);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int L = digitalRead(2);
  int M = digitalRead(3);
  int R = digitalRead(4);
  Serial.print("Value of Right Sensor is : " + String(R));
  Serial.print("\n");
  Serial.print("Value of Left Sensor is : " + String(L));
  Serial.print("\n");
  Serial.print("Value of Middle Sensor is : " + String(M));
  Serial.print("\n");
  delay(1000);

  if ((L = 0) && (M = 0) && (R = 1)) { //Left T segment
    turnleft();
  }

  if ((L = 0) && (M = 1) && (R = 0)) { //Vertical T segment
    turnleft();
  }

  if ((L = 0) && (M = 1) && (R = 1)) { //Left turn
    turnleft();
  }

2  if ((L = 1) && (M = 0) && (R = 0)) { //Right T segment
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(100);
  }

  if ((L = 1) && (M = 0) && (R = 1)) { //Straight line
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(100);
  }

  if ((L = 1) && (M = 1) && (R = 0)) { //Right turn
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(100);
    turnright();
  }

  if ((L = 1) && (M = 1) && (R = 1)) { //Dead End
    moveRobot("Forward");
    delay(100);
    moveRobot("Stop");
    delay(100);

    int L_temp = digitalRead(2);
    int M_temp = digitalRead(3);
    int R_temp = digitalRead(4);

    if ((L_temp == 1) && (M_temp == 1) && (R_temp == 1)) {
      turnleft();
    }
  }

  if ((L = 0) && (M = 0) && (R = 0)) { //4 Way Intersection
    moveRobot("Forward");
    delay(200);
    moveRobot("Stop");
    delay(200);

    int L_temp = digitalRead(2);
    int M_temp = digitalRead(3);
    int R_temp = digitalRead(4);

    if ((L_temp == 0) && (M_temp == 0) && (R_temp == 0)) {
      moveRobot("Stop");
      exit(0);
    }
    else {
      turnleft();
    }
  }
}
