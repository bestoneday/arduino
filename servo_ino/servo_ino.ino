void softwarePWM(int pin,int T,int D)
{
   digitalWrite(pin,LOW);
   digitalWrite(pin,HIGH);
  
   delayMicroseconds(T);
  digitalWrite(pin,LOW);
   delayMicroseconds(D-T);
   
}
int con=700;
void setup()
{
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}
void loop()
{ int num;
  if(Serial.available())
    num=Serial.read(),Serial.print(con,DEC),Serial.write('\n');;
  if(num=='w') con+=50;
  else if(num=='d') con-=50;
  softwarePWM(9,con,20000);
  delay(30);
}
