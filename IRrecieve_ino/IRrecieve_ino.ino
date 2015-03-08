class IRrecieve
{
  public:
    byte result[4];
    IRrecieve(int _pin)
      {
        pin=_pin;
        pinMode(pin,INPUT);
        result[0]=0;
        result[1]=0;
        result[2]=0;
        result[3]=0;
      }
    int HowLongLow()
      {
        int time=0;
        while(digitalRead(pin)==LOW)
          {
            delayMicroseconds(1);
            time++;
          }
        return time;  
      }  
    boolean LowLevelDetect(int time)
      {
        int i;
        delayMicroseconds(20);
        for(i=0;i<time-40;i++)
          {
            if(digitalRead(pin)==HIGH) 
              return false;
            delayMicroseconds(1);  
          }
        delayMicroseconds(20);  
        return true;
      }
     boolean HighLevelDetect(int time)
      {
        int i;
        delayMicroseconds(20);
        for(i=0;i<time-40;i++)
          {
            if(digitalRead(pin)==LOW) 
              return false;
            delayMicroseconds(20);
          }
        delayMicroseconds(20);
        return true;
      }  
   boolean head()
      {
       if(LowLevelDetect(900)&&HighLevelDetect(450))
         return true;
       return false;
      }  
   boolean recieve()
      { 
        int i,k;
        for(i=0;i<4;i++)
          {for(k=0;k<7;k++)
            {
              while(digitalRead(pin==LOW));
              if(HowLongLow()>1000)
                result[i]|=0x80;
              result[i]>>=1;  
            }
              while(digitalRead(pin==LOW));
              if(HowLongLow()>1000)
                result[i]|=0x80;
          }
      }
    boolean rewind()
      {
        result[0]=0;
        result[1]=0;
        result[2]=0;
        result[3]=0;
      } 
 
  private:
    int pin;
    
};
IRrecieve ir(2);
void setup(){
  Serial.begin(9600);
  attachInterrupt(0,function,LOW);
}
void loop(){}
void function()
{
  int i;
  ir.head();
  ir.recieve();
  for(i=0;i<4;i++)
    Serial.println(ir.result[i],DEC);
  ir.rewind();
}
