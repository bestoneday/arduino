const int led1=2;
const int led2=3;
const int led3=4;
const int led4=5;
void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}
void loop()
{
  byte num;
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
 
  if(Serial.available()) 
  {switch (num=Serial.read())
    {
      case '1':digitalWrite(led1,LOW);break;
    case '2':digitalWrite(led2,LOW);break;
    case '3':digitalWrite(led3,LOW);break;
    case '4':digitalWrite(led4,LOW);break;
    }
   Serial.write(num);
   delay(600);
   
  } 
}
