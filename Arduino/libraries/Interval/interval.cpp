#include <Arduino.h>
#include "interval.h"

Interval::Interval(int interval, void(*process)()){
  m_interval = interval;
  m_process = process;
  m_previousMillis = 0;
  m_state = 0;
}

void Interval::check() {
  if(!m_state) return;
  unsigned long currentMillis = millis();

  if(currentMillis - m_previousMillis >= m_interval) {
    m_previousMillis= currentMillis;

    if(m_process) 
      m_process();
  }
}

void Interval::start() {
  m_state = 1;
  m_previousMillis = millis();
}

void Interval::pause() {
  m_state = 0;
}

int Interval::getState() {
  return m_state;
}