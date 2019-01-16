#include <led.h>

int Button = 2;

Led led(3);

void setup() {
  pinMode(Button, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(Button);

  if(buttonState) { // 버튼이 눌렸을때
    led.toggle(); 
  }
  
  delay(1);
}
