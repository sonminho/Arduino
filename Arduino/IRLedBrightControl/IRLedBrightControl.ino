#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <boarddefs.h>
#include "IrConst.h"

const int irPin = 11;
const int ledPin = 9;
int ledBright = 0;
int br_step = 1;
long oldSignal = 0;

decode_results results;
IRrecv irrecv(irPin);

void setup() {
  Serial.begin(9600);
  // 적외선 리모컨 수신 시작
  irrecv.enableIRIn();
  // 13번 핀에 연결된 LED를 리모컨 수신시 점멸
  irrecv.blink13(true);
  pinMode(ledPin, OUTPUT);
}

void led_bright(long code) {
  if (code == IR_PLUS) {
    if (ledBright < 255) {
      ledBright += br_step;
    }
  }
  else if (code == IR_MINUS) {
    if (ledBright > 0) {
      ledBright -= br_step;
    }
  }
}

void loop() {
  //수신된 코드가 있는지 검사
  if (irrecv.decode(&results)) {
    // 0xFFFFFFFF를 제외하고 출력
    if (results.value != 0xFFFFFFFF) {
      led_bright(results.value);
      oldSignal = results.value;
    }
    else {
      led_bright(oldSignal);
    }
    Serial.println(ledBright);
    // 다음 수신 준비
    irrecv.resume();
  }

  analogWrite(ledPin, ledBright);
  delay(10);
}
