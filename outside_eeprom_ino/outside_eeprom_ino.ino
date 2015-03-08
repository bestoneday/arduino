#ifndef NODEBUG
#define ASSERT_INIT() \
        Serial.begin(9600);\
        pinMode(13,OUTPUT);\
        
#define ASSERT(condition) \
        if(!condition) \
        {  Serial.println(__LINE__);\
          while(1) digitalWrite(13,HIGH),delay(500),digitalWrite(13,LOW),delay(500); \
        }                       
#else
#define ASSERT_INIT() NULL
#define ASSERT(s) NULL
#endif
class eeprom
{
  public:
    int sda;
    int scl;
    int device_addr;
   
  eeprom(int _sda,int _scl,int _device_addr)
  {
    sda=_sda;
    scl=_scl;
    device_addr=_device_addr;
    
  }
  void start()
  {
    pinMode(sda,OUTPUT);
    pinMode(scl,OUTPUT);
    digitalWrite(scl,LOW);
    delayMicroseconds(5);
    digitalWrite(sda,HIGH);
    delayMicroseconds(5);
    digitalWrite(scl,HIGH);
    delayMicroseconds(5);
    digitalWrite(sda,LOW);
    delayMicroseconds(5);
    
  }
  unsigned char get_byte()
  {
    int i;
    int val=0;
    pinMode(sda,INPUT_PULLUP);
    for(i=0;i<8;i++)
      {
        digitalWrite(scl,LOW);
        delayMicroseconds(5);
        digitalWrite(scl,HIGH);
        delayMicroseconds(5);
        if(digitalRead(sda)) val|=1;
        val<<=1;
        
      }
    pinMode(sda,OUTPUT);  
  }
  void send_byte(unsigned char val)
  {
    int i;
    digitalWrite(scl,LOW);
    delayMicroseconds(5);
    for(i=0;i<8;i++)
      {
        if(val&0x80)
          digitalWrite(sda,HIGH);
        else 
          digitalWrite(sda,LOW);
        val<<=1;  
        delayMicroseconds(5);
        digitalWrite(scl,HIGH);
        delayMicroseconds(5);
        digitalWrite(scl,LOW);
        delayMicroseconds(5);
      }
  }
  
  boolean get_ack()
  {
    pinMode(sda,INPUT_PULLUP);
    digitalWrite(scl,HIGH);
    delayMicroseconds(5);
    if(digitalRead(sda)){ pinMode(sda,OUTPUT);return true;}
    else {pinMode(sda,OUTPUT);return false;}
    
  }
  
    void Stop()
    {
      digitalWrite(scl,LOW);
      delayMicroseconds(5);
      digitalWrite(sda,LOW);
      delayMicroseconds(5);
      digitalWrite(scl,HIGH);
      delayMicroseconds(5);
      digitalWrite(sda,HIGH);
      delayMicroseconds(5);
      
    }
  void Write(unsigned char addr_inside,unsigned char Size,unsigned char *Catch)
  {
    int addr;
    int i;
    start();
    addr=0xAE;
    addr&=(device_addr<<1);
    send_byte(addr_inside);
    ASSERT(!get_ack());
    for(i=0;i<Size;Size++)
      {
         send_byte(Catch[i]);
         ASSERT(!get_ack());
         
      }
    Stop();
    } 
    
    
     void Read(unsigned char addr_inside,unsigned char Size,unsigned char *buffer)
    {
    int addr;
    int i;
    start();
    addr=0xAF;
    addr&=device_addr<<1;
    send_byte(addr_inside);
    ASSERT(!get_ack());
    for(i=0;i<Size;Size++)
      {
         buffer[i]=get_byte();
         ASSERT(!get_ack());
         
      }
    Stop();
    } 
  
  
};
eeprom my(7,6,7);
void setup(){
  ASSERT_INIT()
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  
}
void loop(){
    unsigned char data;
    my.Write(0,1,&data);
    
  
}

