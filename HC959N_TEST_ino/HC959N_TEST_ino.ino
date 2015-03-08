#include <SPI.h>
#define RCK 7
byte num=0;
void setup()
{
  Serial.begin(9600);
 SPI.begin(); 
 pinMode(MOSI,OUTPUT);
 pinMode(SCK,OUTPUT);
 pinMode(RCK,OUTPUT);
 digitalWrite(RCK,LOW);
}



void loop()
{
    byte t;
 if(Serial.available())
    {
      t=Serial.read();
     if(t=='w') num++;
     else if(t=='d') num--;
     
       SPI.transfer(num);
      digitalWrite(RCK,HIGH);
      digitalWrite(RCK,LOW);
    } 
}


