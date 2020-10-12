#include <Servo.h>
Servo Myservo;
int Speed = 128; // controls the speed
float cm;
const unsigned int MAX_DIST = 23200;



void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);//sets analog pin for motor
  pinMode(7,OUTPUT);//sets digital pin for motor
  pinMode(8,OUTPUT);//sets digital pin fopr motor
  digitalWrite(7,LOW);//starts out not moving
  digitalWrite(8,LOW);

  pinMode(9,OUTPUT);//tells sensor to range find
  digitalWrite(9,LOW);

  Myservo.attach(11);
  Myservo.write(90);

}

void loop() {
  analogWrite(6,Speed); //sets the speed

  Serial.println("forward");//tells the user the direction 
  digitalWrite(7,HIGH);//7 and 8 might need to be reversed
  digitalWrite(8,LOW);

 cm = Distance();

  if (cm < 17){
    Myservo.write(115);

}
if (cm > 23){
  Myservo.write(65);
}
if (cm<23 && cm>17) {
  Myservo.write(90);
}

}


float Distance(){

  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;

  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  digitalWrite(9,LOW);

  while(digitalRead(10)== 0);
  t1 = micros();

  while(digitalRead(10) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  cm = pulse_width / 58.0;

    if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm);
    Serial.print(" cm \t");
}
return cm;
}
