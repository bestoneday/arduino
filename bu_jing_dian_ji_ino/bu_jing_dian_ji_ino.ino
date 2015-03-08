
class stepper
{
  public:
    int in[4];
    int dir;
    int stage;
    int order;
  stepper(int _in1,int _in2,int _in3,int _in4)
  {
    in[0]=_in1;
    in[1]=_in2;
    in[2]=_in3;
    in[3]=_in4;
    pinMode(_in1,OUTPUT);
    pinMode(_in2,OUTPUT);
    pinMode(_in3,OUTPUT);
    pinMode(_in4,OUTPUT);
    dir=1;
    stage=0;
    order=0;
    
  }  
  
  void Step()
  {
    if(stage==0) 
    {
      stage=1;
      set(order);  
    }
    if(stage==1)
    {
      stage=0;
      set2(order);   
    }
    
    if(dir<0)  order--;
    if(dir>0)  order++;
    if(order==4) order=0;
    if(order==-1) order=3;
  }
  void set(int choose)
  {
    int i;
    for(i=0;i<4;i++)
      {
        digitalWrite(in[i],LOW);
      }
    digitalWrite(in[choose],HIGH);  
  }
  
  void turn()
  {
    dir=-dir;
  }
  void set2(int choose)
  {
    int i;
    for(i=0;i<4;i++)
      {
        digitalWrite(in[i],LOW);
      }
     digitalWrite(in[choose],HIGH);  
     digitalWrite(in[(choose+1*dir)%4],HIGH);    
  }  
  void run(int Speed)
  {
    Step();
    delay(map(Speed,0,100,200,2));
    
  }
};
stepper my(13,12,11,10);
void setup(){

  Serial.begin(9600);
  
}
void loop(){
  int i;
  i=0;
  while(1)
  {
    my.run(100);
    if(Serial.available())
      if(Serial.read()=='t')
        my.turn();
  }
}
