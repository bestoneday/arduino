int led=12;
void setup()
{
  pinMode(led,OUTPUT);
}
void loop()
{
  digitalWrite(led,LOW);
  delay(2000);
  digitalWrite(led,HIGH);
  delay(2000);
}
