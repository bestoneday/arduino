class digiTube
{private:
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int DP;
  int first;
  int second;
  int third;
  int forth;
  public:
    digiTube(int _a,int _b,int _c,int _d,int _e,int _f,int _g,int _DP){
      a=_a;b=_b;c=_c;d=_d;e=_e;f=_f;g=_g;DP=_DP;
      pinMode(a,OUTPUT);
      pinMode(b,OUTPUT);
      pinMode(c,OUTPUT);
      pinMode(d,OUTPUT);
      pinMode(e,OUTPUT);
      pinMode(f,OUTPUT);
      pinMode(g,OUTPUT);
      pinMode(DP,OUTPUT);
      }
    digiTube(int _a,int _b,int _c,int _d,int _e,int _f,int _g,int _DP,int _first,int _second,int _third,int _forth){
      a=_a;b=_b;c=_c;d=_d;e=_e;f=_f;g=_g;DP=_DP;first=_first;second=_second;third=_third;forth=_forth;
      pinMode(a,OUTPUT);
      pinMode(b,OUTPUT);
      pinMode(c,OUTPUT);
      pinMode(d,OUTPUT);
      pinMode(e,OUTPUT);
      pinMode(f,OUTPUT);
      pinMode(g,OUTPUT);
      pinMode(DP,OUTPUT);
      pinMode(first,OUTPUT);
      pinMode(second,OUTPUT);
      pinMode(third,OUTPUT);
      pinMode(forth,OUTPUT);
      }
    void show(int num,int dp){
      if(dp==1) digitalWrite(DP,HIGH);
        else if(dp==0) digitalWrite(DP,LOW);    
      switch(num)
      {case 0:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 1:digitalWrite(a,LOW);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 2:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,LOW);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,LOW);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 3:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 4:digitalWrite(a,LOW);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 5:digitalWrite(a,HIGH);
              digitalWrite(b,LOW);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 6:digitalWrite(a,HIGH);
              digitalWrite(b,LOW);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 7:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 8:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 9:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;      
      };
    }
void show(int num,int p,int dp){
      if(dp==1) digitalWrite(DP,HIGH);
        else if(dp==0) digitalWrite(DP,LOW);   
     switch(p){
       case 1:digitalWrite(first,LOW);
              digitalWrite(second,HIGH);
              digitalWrite(third,HIGH);
              digitalWrite(forth,HIGH);break;
       case 2:digitalWrite(first,HIGH);
              digitalWrite(second,LOW);
              digitalWrite(third,HIGH);
              digitalWrite(forth,HIGH);break;
       case 3:digitalWrite(first,HIGH);
              digitalWrite(second,HIGH);
              digitalWrite(third,LOW);
              digitalWrite(forth,HIGH);break;
       case 4:digitalWrite(first,HIGH);
              digitalWrite(second,HIGH);
              digitalWrite(third,HIGH);
              digitalWrite(forth,LOW);break;
     };
    switch(num)
      {case 0:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 1:digitalWrite(a,LOW);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 2:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,LOW);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,LOW);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 3:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 4:digitalWrite(a,LOW);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 5:digitalWrite(a,HIGH);
              digitalWrite(b,LOW);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 6:digitalWrite(a,HIGH);
              digitalWrite(b,LOW);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 7:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,LOW);
              digitalWrite(e,LOW);
              digitalWrite(f,LOW);
              digitalWrite(g,LOW);
              digitalWrite(DP,LOW);break;
        case 8:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,HIGH);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;
        case 9:digitalWrite(a,HIGH);
              digitalWrite(b,HIGH);
              digitalWrite(c,HIGH);
              digitalWrite(d,HIGH);
              digitalWrite(e,LOW);
              digitalWrite(f,HIGH);
              digitalWrite(g,HIGH);
              digitalWrite(DP,LOW);break;      
      }
    }
};
digiTube my(2,3,4,5,6,7,8,9,10,11,12,13);
void setup(){
  Serial.begin(9600);
}
int num=0;int p=1;int dp=0;
void loop(){

  if(Serial.available())
  {num=Serial.read()-'0';
    delay(2);
    p=Serial.read()-'0';
    delay(2);
    dp=Serial.read()-'0';}
  my.show(num,p,dp);
}

