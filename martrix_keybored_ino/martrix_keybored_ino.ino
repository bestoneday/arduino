#ifndef NODEBUG
#define ASSERT(CONDITION)  if(!CONDITION)  \
                           {digitalWrite(13,HIGH); \
                            while(1);        \
                           };
#else
#define ASSERT(CONDITION)   NULL
#endif        

class martrix_keybored
{
  public:
  martrix_keybored(int _pin0,int _pin1,int _pin2,int _pin3,int _pin4,int _pin5,int _pin6,int _pin7)
  {
      pin[0]=_pin0;
      pin[1]=_pin1;
      pin[2]=_pin2;
      pin[3]=_pin3;
      pin[4]=_pin4;
      pin[5]=_pin5;
      pin[6]=_pin6;
      pin[7]=_pin7; 
      pinMode(13,OUTPUT);
      digitalWrite(13,LOW);
  }
  
unsigned char function(void)
   {
     while(1)
       {
         if(row_read()!=10) 
           {  
              delay(50);
              if((flag=row_read())!=10)
                {
                  flag<<=4;
                  flag=flag||col_read();
                  ASSERT(flag!=0x01);
                  return flag;
                }
              continue;  
           }
       }
    }
  
  
  private:
    int pin[8];
    int flag;
  
  unsigned char col_read(void)
  {
    unsigned char i;
    for(i=0;i<4;i++)
      {
        pinMode(pin[i],OUTPUT);
        digitalWrite(pin[i],HIGH);
      }
    for(i=4;i<8;i++)
      {
        pinMode(pin[i],INPUT);
        if(digitalRead(pin[i])==HIGH)
          return i-4; 
      }
    return 10;

    
 
  }
  unsigned char row_read(void)
  {
    unsigned char i;
    for(i=4;i<8;i++)
      {
        pinMode(pin[i],OUTPUT);
        digitalWrite(pin[i],HIGH);
      }
    for(i=0;i<4;i++)
      {
        pinMode(pin[i],INPUT);
        if(digitalRead((pin[i])==HIGH))  
          return i;
      }
     return 10; 
  }


};

martrix_keybored my(2,3,4,5,6,7,8,9);
void setup()
  {
    Serial.begin(9600);
  }
void loop()
  {
    switch ( my.function())
      {
        case 0x00:Serial.write("1");break;
        case 0x01:Serial.write("2");break;
        case 0x02:Serial.write("3");break;
        case 0x03:Serial.write("A");break;
        case 0x10:Serial.write("4");break;
        case 0x11:Serial.write("5");break;
        case 0x12:Serial.write("6");break;
        case 0x13:Serial.write("B");break;
        case 0x20:Serial.write("7");break;
        case 0x21:Serial.write("8");break;
        case 0x22:Serial.write("9");break;
        case 0x23:Serial.write("C");break;
        case 0x30:Serial.write("*");break;
        case 0x31:Serial.write("0");break;
        case 0x32:Serial.write("#");break;
        case 0x33:Serial.write("D");break;
      }
  }
