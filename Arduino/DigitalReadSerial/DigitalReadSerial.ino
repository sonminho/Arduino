#include <led.h>

int Button = 2;

Led led(3);

void setup() {
  pinMode(Button, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(Button);

  if(buttonState) {
    led.toggle();
  }
  
  delay(1);
}
