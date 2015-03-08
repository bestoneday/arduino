class IR
{
  private:
    int pin;
    int temp;
  public:
    unsigned long result;
    IR(int _pin)
      {
        pin=_pin;
        pinMode(pin,INPUT);
        result=0;

      }
    void reject()
      {
        for(temp=31;temp>0;temp--)
        {if(digitalRead(pin)==HIGH)
           result|=1;
        result<<=1;
        delayMicroseconds(26);
        }
        result|=1;
      }
     void remind()
       {
         result=0;
       }
};

IR ir(2);

void function()
{
  ir.reject();
  Serial.println(ir.result);
  ir.remind();
}
void setup()
{
  Serial.begin(9600);
  interrupts();
  attachInterrupt(0,function,CHANGE);
  
}
void loop()
{

}


  
  
