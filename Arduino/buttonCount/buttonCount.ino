#include <led.h>

const int buttonPin = 2;

int buttonState; // 버튼의 현재 상태
int lastButtonState = LOW;  // 버튼의 이전 상태
int count = 0;

void setup() { 
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);   
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if(buttonState != lastButtonState) {
    if(buttonState == HIGH) {
      Serial.println(++count);
    }
  }
  lastButtonState = buttonState;
  delay(1);
}
