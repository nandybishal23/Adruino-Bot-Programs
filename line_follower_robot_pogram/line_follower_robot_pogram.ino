void setup() {
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}

void moveRobot(String motion)
{
if(motion == "Forward")
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.print("Forward");
  }
  if(motion == "Backward")
  {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.print("Backward");
  }
  if(motion == "Left")
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.print("Left");
  }
  if(motion == "Right")
  {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.print("Right");
  }
  if(motion == "Stop")
  {
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    Serial.print("Stop");
  }
}
void loop() {
// put your main code here, to run repeatedly:
int Right = analogRead(A0);
int Left = analogRead(A1);
Serial.print("Value of Right Sensor is : " + String(Right));
Serial.print("\n");
Serial.print("Value of Left Sensor is : " + String(Left));
delay(1000);

if(Right > 700 && Left > 700) // 600 should be at first checked for our bot 
{
  moveRobot("Forward");
}
if(Right < 700 && Left < 700)
{
  moveRobot("Stop");
}
if(Right < 700 && Left > 700)
{
  moveRobot("Right");
}
if(Right > 700 && Left < 700)
{
  moveRobot("Left");
}
}
