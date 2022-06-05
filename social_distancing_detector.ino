#define trigger 4
#define echo 6
#define led 13
#define spk 11
double duration;
double distance;
double threshold = 2.00;
void setup()
{
	pinMode(trigger,OUTPUT);
	pinMode(echo,INPUT);
	pinMode(led,OUTPUT);
	pinMode(spk,OUTPUT);
  	Serial.begin(9600);
}
void loop()
{
  	noTone(spk);
	digitalWrite(trigger,HIGH);
  	delay(10);
	digitalWrite(trigger,LOW);
	duration = pulseIn(echo,HIGH);
  	distance = duration*(172.205*0.000001);
  	Serial.println(distance);
  	if(distance<=threshold)
    {
      digitalWrite(led,HIGH);
      analogWrite(spk,HIGH);
      delay(40);
    }  
  	else
    {
      digitalWrite(led,LOW);
      noTone(spk);
    }  
}