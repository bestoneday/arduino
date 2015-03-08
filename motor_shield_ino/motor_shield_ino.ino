unsigned char control_code[4][3]={0x20,0x10,0x00,0x40,0x08,0x00,0x80,0x02,0x00,0x04,0x01,0x00};

class motor_shield
{
  private:
    int DIR_LATCH;
    int DIR_EN;
    int DIR_CLK;
    int DIR_SER;
    int PWM_M1;
    int PWM_M2;
    int PWM_M3;
    int PWM_M4;
    int PWM_SERVO1;
    int PWM_SERVO2;
    unsigned char control;
  public:
     motor_shield()
      {
        DIR_LATCH=12;
        DIR_EN=7;
        DIR_CLK=4;
        DIR_SER=8;
        PWM_M4=5;
        PWM_M3=6;
        PWM_SERVO2=9;
        PWM_SERVO1=10;
        PWM_M1=11;
        PWM_M2=3;
        control=0;
        pinMode(DIR_LATCH,OUTPUT);
        pinMode(DIR_EN,OUTPUT);
        pinMode(DIR_CLK,OUTPUT);
        pinMode(DIR_SER,OUTPUT);
        pinMode(PWM_M1,OUTPUT);
        pinMode(PWM_M2,OUTPUT);
        pinMode(PWM_M3,OUTPUT);
        pinMode(PWM_M4,OUTPUT);
        pinMode(PWM_SERVO1,OUTPUT);
        pinMode(PWM_SERVO2,OUTPUT);
        
      } 
  void spi()
  {
    int i;
    for(i=0;i<8;i++)
      {
        if(control%2==1)  digitalWrite(DIR_SER,HIGH);
        else digitalWrite(DIR_SER,LOW);
        control>>=1;
        digitalWrite(DIR_CLK,HIGH);
        digitalWrite(DIR_CLK,LOW);
      }
     digitalWrite(DIR_LATCH,HIGH);
     digitalWrite(DIR_LATCH,LOW);
  }

  
  void state_control(unsigned char M1,unsigned char M2,unsigned char M3,unsigned char M4) //0 for on, 1 for back,2 for off 
  {
    control=0;
    control=control|control_code[0][M1]|control_code[1][M2]|control_code[2][M3]|control_code[3][M4];
  }
  
  void servo1_run(int angle)
  {
    int temp;
    temp=map(angle,-90,90,700,2500);
    digitalWrite(PWM_SERVO1,HIGH);
    delayMicroseconds(temp);
    digitalWrite(PWM_SERVO1,LOW);
    delayMicroseconds(20000-temp);
  }
  void servo2_run(int angle)
  {
    int temp;
    temp=map(angle,-90,90,700,2500);
    digitalWrite(PWM_SERVO2,HIGH);
    delayMicroseconds(temp);
    digitalWrite(PWM_SERVO2,LOW);
    delayMicroseconds(20000-temp);
  }
  void motor_run(int t,int T)
    {
      digitalWrite(PWM_M1,HIGH);
      digitalWrite(PWM_M2,HIGH);
      digitalWrite(PWM_M3,HIGH);
      digitalWrite(PWM_M4,HIGH);
      delayMicroseconds(t);
      digitalWrite(PWM_M1,LOW);
      digitalWrite(PWM_M2,LOW);
      digitalWrite(PWM_M3,LOW);
      digitalWrite(PWM_M4,LOW);
      delayMicroseconds(T-t);
    }
  
};
motor_shield my;

void setup(){
  Serial.begin(9600);
  }
void loop(){
  my.state_control(2,2,2,2);
  my.spi();
  while(1)
  {
   my.motor_run(39000,40000);
   my.servo1_run(0);
   my.servo2_run(0);
  }
  
}
