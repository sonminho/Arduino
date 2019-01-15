#ifndef LED_H
#define LED_H

class Led {
private:
  const int m_pin; // 핀 번호
  boolean m_state; // LED ON/OFF 상태
  int m_analog_value;

public:
   Led(int pin, boolean state = LOW);
   void on();
   void off();
   void set(boolean state);
   void toggle(); // 현재 상태를 반전시켜 출력
   boolean getState() { // 현재 상태 반환
      return m_state;  
   }
   void setValue(int value);
};

#endif
