class detect
{
  public:
    int trig;
    int echo;
  detect(int _trig,int _echo)
  {
    trig=_trig;
    echo=_echo;
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    digitalWrite(echo,LOW);
    digitalWrite(trig,LOW);  
      
}
  long go()
  {
    unsigned char time=0;
    digitalWrite(trig,HIGH);
    digitalWrite(trig,LOW);
    while(digitalRead(echo)==LOW);
    while(digitalRead(echo)==HIGH)
      { 
        time++;
       delayMicroseconds(1);
      }
    
    
    digitalWrite(trig,LOW);
    return time/15;
}
};
detect my(7,6);
void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.println(my.go(),DEC);
  delay(1000);
}
