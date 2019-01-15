#include <led.h>

Led led(3);

void setup() {
  
}

void loop() {
  led.toggle();
  delay(1000);
}
