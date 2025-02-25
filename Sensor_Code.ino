#include <Stepper.h>
int dir = 7;
int step = 6;
const int trig = 4;
const int echo = 3;
long duration;
int buzz = 13;
int distance;
int steppist = 250;
int stepsper = 200;
Stepper stepper = Stepper(stepsper,step,dir);
void setup() {
  // put your setup code here, to run once:
  
  stepper.setSpeed(50);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,HIGH);



}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
  if(distance>20)
  {
    stepper.step(steppist);
    steppist = steppist *-1;
    
  }
  
  else
  {
    stepper.step(0);
    
  }
 
}
