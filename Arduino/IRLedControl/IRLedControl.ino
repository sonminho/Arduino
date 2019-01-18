#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <boarddefs.h>
#include "IrConst.h"

const int irPin = 11;
const int ledPin = 9;
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

void loop() {
  //수신된 코드가 있는지 검사
  if (irrecv.decode(&results)) {
    // 0xFFFFFFFF를 제외하고 출력
    if (results.value != 0xFFFFFFFF) {
      Serial.print("Receive Code is 0x");
      Serial.println(results.value, HEX);

      if (results.value == IR_PLUS) {
        digitalWrite(ledPin, HIGH);
      }
      else if (results.value == IR_MINUS) {
        digitalWrite(ledPin, LOW);
      }
    }
    // 다음 수신 준비
    irrecv.resume();
  }
}
