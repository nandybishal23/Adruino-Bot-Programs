#define B1 4
#define B2 5
#define B3 6
#define B4 7

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(B1,INPUT);
pinMode(B2,INPUT);
pinMode(B3,INPUT);
pinMode(B4,INPUT);
//pinMode(A0,INPUT);
//pinMode(A1,INPUT);
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
int D1 = analogRead(B1);
int D2 = analogRead(B2);
int D3 = analogRead(B3);
int D4 = analogRead(B4);
//Serial.print("Value of Right Sensor is : " + String(Right));
//Serial.print("\n");
//Serial.print("Value of Left Sensor is : " + String(Left));
//delay(1000);
if((D1 == 1) && (D2 == 0)  &&  (D3 == 1) && (D4 == 0))
{
  moveRobot("Forward");
}
if((D1 == 0) && (D2 == 0)  &&  (D3 == 0) && (D4 == 0))
{
  moveRobot("Stop");
}
if((D1 == 0) && (D2 == 1)  &&  (D3 == 1) && (D4 == 0))
{
  moveRobot("Right");
}
if((D1 == 1) && (D2 == 0)  &&  (D3 == 0) && (D4 == 1))
{
  moveRobot("Left");
}
}
