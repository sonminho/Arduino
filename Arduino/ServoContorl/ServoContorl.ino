 #include <Servo.h>

Servo servo;
int servoPin = 9;
int potPin = A0;
int val;

void setup() {
  servo.attach(servoPin);
  servo.write(0);
  delay(15);
}

void loop() {
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 179);
  
  servo.write(val);
  delay(15);
}
