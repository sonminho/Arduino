#include <interval.h>
#include <led.h>

//Led led(3);
Led leds[] = {Led(3), Led(6), Led(13)};

int brightness = 0; // 밝기
int fadeAmount = 10; // 밝기 조정 간격
int currentLed = 0; // 현재 작업 LED 인덱스

inline void updateBrightness() {
  brightness = brightness + fadeAmount;

  if(brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  if(brightness == 0) {
    leds[currentLed].setValue(0);
    currentLed = (currentLed+1) % 3;
  }
}

Interval interval(30, []()->void {
  leds[currentLed].setValue(brightness);
  updateBrightness();
});

void setup() {
}

void loop() {
  interval.check();
  
  delay(30);
}
