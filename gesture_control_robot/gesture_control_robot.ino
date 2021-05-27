void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
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
int D0=analogRead(4);
int D1=analogRead(5);
int D2=analogRead(6);
int D3=analogRead(7.
);

if((D3==0)&&(D2==0)&&(D1==1)&&(D0==0))
{
  moveRobot("Forward");
}
if((D3==1)&&(D2==0)&&(D1==0)&&(D0==0))
{
  moveRobot("Backward");
}
if((D3==0)&&(D2==1)&&(D1==0)&&(D0==0))
{
  moveRobot("Left");
}
if((D3==0)&&(D2==1)&&(D1==1)&&(D0==0))
{
  moveRobot("Right");
}
if((D3==0)&&(D2==1)&&(D1==0)&&(D0==1))
{
  moveRobot("Stop");
}
}
