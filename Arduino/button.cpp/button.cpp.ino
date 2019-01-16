#include <Arduino.h>
#include "button.h"

const unsigned long debounceDelay = 50;
 
Button::Button(int pin, fn_p click, int mode = UP_EDGE) : m_pin(pin){
  pinMode(m_pin, INPUT);
  m_click = click;
  m_buttonState = LOW;  
}

void Button::check() {
  int reading = digitalRead(m_pin);
  if(reading != m_lastButtonState) { // 이전 상태와 달라짐, 시간 측정
    m_lastDebounceTime = millis();
  }

  // 지연 시간 이내의 변화라면 무시
  if((millis() - m_lastDebounceTime) > debounceDelay) {
    if(reading != m_buttonState) {
      m_buttonState = reading;
      if(m_buttonState = m_mode) {
        if(m_click) m_click();
      }
    }
  }
  m_lastButtonState = reading;
}

int Button::read() {
  return digitalRead(m_pin);
}

int Button::read(fni_p pFn) {
  int value = digitalRead(m_pin);
  pFn(value);
  return value;
}
