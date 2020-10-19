//dip =2, dip2 = 4, dip3 = 7, dip4 = 8;
//motor1right = 6, motor1left = 9;
//motor2right = 5, motor2left = 3;

int dip1, dip2, dip3, dip4, potentiometer, speed;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}
void loop()
{
  potentiometer = analogRead(A0);
  speed = map(potentiometer, 0, 1023, 0, 255);
  Serial.println(potentiometer);
  
  Serial.println(speed);
  
  dip1 = digitalRead(2);
  dip2 = digitalRead(4);
  dip3 = digitalRead(7);
  dip4 = digitalRead(8);
  
  delay(25);
  
  if (dip1 == 0 && dip2 == 0 && dip3 == 0 && dip4 == 0){
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
  }
  else if (dip1 == 1 && dip2 == 0 && dip3 == 0 && dip4 == 0){
    analogWrite(6, speed);
    analogWrite(5, speed);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
  }
  else if (dip1 == 0 && dip2 == 1 && dip3 == 0 && dip4 == 0){
    analogWrite(9, speed);
    analogWrite(3, speed);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  else if (dip1 == 0 && dip2 == 0 && dip3 == 1 && dip4 == 0){
    analogWrite(9, speed);
    analogWrite(5, speed);
    digitalWrite(6, LOW);
    digitalWrite(3, LOW);
  }
  else if (dip1 == 0 && dip2 == 0 && dip3 == 0 && dip4 == 1){
    analogWrite(6, speed);
    analogWrite(3, speed);
    digitalWrite(9, LOW);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
  }
  delay(500);
}