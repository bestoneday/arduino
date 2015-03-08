void softwarePWM(int pin,int T,int D)
{
   digitalWrite(pin,LOW);
   digitalWrite(pin,HIGH);
  
   delayMicroseconds(T);
  digitalWrite(pin,LOW);
   delayMicroseconds(D-T);
   
}
void setup(){
  pinMode(9,OUTPUT);
Serial.begin(9600);
}
long time=millis();
int music;
void loop(){
  if((millis()-time)%200==0)
    music=analogRead(0); 
  softwarePWM(9,(music+800)/2,music+800);
  

}
