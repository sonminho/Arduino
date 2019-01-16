#include <interval.h>
#include <led.h>
#include "button.h"

Led headLight(5);
Led blinkLight(6);
Led breakLight(7);

Interval blinkInterval(500, []()->void{blinkLight.toggle();});

Button headBtn(8, []()->void{headLight.toggle();});

Button blinkBtn(9, []()->void {
  if(blinkInterval.getState()) {
    blinkLight.off();
    blinkInterval.pause();
  } else {
    blinkInterval.start();
  }
});

Button breakBtn(10);

void setup() {
  
}

void loop() {
  headBtn.check();
  blinkInterval.check();
  blinkBtn.check();
  breakBtn.read([](int v)->void{breakLight.set(v);});
}
