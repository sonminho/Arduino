#include <Arduino.h>
#include "button.h"

const unsigned long debounceDelay = 50;

Button::Button(int pin) : Button(pin, NULL) {
  
}

Button::Button(int pin, fn_p click, int mode = UP_EDGE) : m_pin(pin) {
  m_mode = mode;
  m_click = click;
  m_buttonState = LOW;
  pinMode(m_pin, INPUT);
}

void Button::check(){
  int reading = digitalRead(m_pin);

  if(reading != m_lastButtonState){
    m_lastDebounceTime = millis();
  }

  if((millis() - m_lastDebounceTime) > debounceDelay){
    if(reading != m_buttonState){
      m_buttonState = reading;
      
      if(m_buttonState == m_mode){
        if(m_click)
          m_click();
      }
     }
   }
    m_lastButtonState = reading;
}

int Button::read(){
  return digitalRead(m_pin);
}

int Button::read(fni_p pFn){
  int value = digitalRead(m_pin);
  pFn(value);
  
  return value;
}
