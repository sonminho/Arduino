#include <led.h>
#include "interval.h"

void blink1();
void blink2();
void blink3();

Led led1(2);
Led led2(3);
Led led3(13);

Interval interval1(1000, blink1);
Interval interval2(2000, blink2);
Interval interval3(3000, blink3);

void blink1() {
  led1.toggle();
}

void blink2() {
  led2.toggle();
}

void blink3() {
  led3.toggle();
}

void setup() {
  
}

void loop() {
  interval1.check();
  interval2.check();
  interval3.check();
}
