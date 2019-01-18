#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include "IrConst.h"
#include <Servo.h>

#define INSERT_MODE 1
#define WAIT_MODE 0

Servo servoMotor;
const int servoMotorPin = 9;
int m_servoAngle = 90;

int mode = 0; // [1] 비밀번호 입력모드
int m_pw[6] = { 1, 3, 2, 1, 2, 3 }; // 비밀번호
int pw[6]; // 입력할 비밀번호
int cnt = 0; // 입력 갯수
int idx = 0; // 비밀번호 인덱스 번호

const int irPin = 11;
decode_results results;

IRrecv irrecv(irPin);

const int soundPin = 3;

int numCheck(long value) {
    int num = -1;
   
    switch(value) {
      case IR_0:
      num = 0;
      break;
      case IR_1:
      num = 1;
      break;
      case IR_2:
      num = 2;
      break;
      case IR_3:
      num = 3;
      break;
  }
  return num;
}

void open() {
  if(m_servoAngle == 90)
    return;
  for(int i = 0; i <= 90; i++) {
    servoMotor.write(i);
    m_servoAngle = i;
    delay(10);
  }
  delay(100);
  mode = WAIT_MODE;
}

void close() {
  if(m_servoAngle == 0)
    return;
  for(int i = 90; i >= 0; i--) {
    servoMotor.write(i);
    m_servoAngle = i;
    delay(10);
  }
  delay(100);
  mode = WAIT_MODE;
}

void sound() {
  int n = 6;

  while(n-- > 0) {
    delay(100);
    digitalWrite(soundPin, HIGH);
    delay(100);
    digitalWrite(soundPin, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // 적외선 리모컨 수신 시작

  pinMode(soundPin, OUTPUT);
  servoMotor.attach(servoMotorPin);
  delay(1000);
  close();
}

void loop() {
  if (irrecv.decode(&results)) { //수신된 코드가 있는지 검사
    if(results.value != 0xFFFFFFFF) { // 0xFFFFFFFF를 제외하고 출력
      if(results.value == IR_PLUS) { // 입력모드로 전환
        Serial.println("PLUS!");
        Serial.println("입력모드로 전환합니다.");
        mode = INSERT_MODE;
        cnt = 0;
        idx = 0;
      }
     else if(results.value == IR_EQ && mode == INSERT_MODE) {
        if(cnt != 6) {
          Serial.println("대기모드로 전환합니다.");
          mode = WAIT_MODE;
          cnt = 0;
          idx = 0;
          close();
        }
        else {
          int i = 0;
          
          for(; i < 6; i++) {
            if(pw[i] != m_pw[i]) {
              break;
            }
          }

          if(i != 6) {
            Serial.println("WRONG");
            close();
          } else {
            Serial.println("RIGHT");
            sound();
            open();
          }
        }
      }
      else if(results.value != IR_EQ && results.value != IR_PLUS){
        if(mode == WAIT_MODE) {
          cnt = 0;
          idx = 0;
          close();
        }
        else {
          int num = numCheck(results.value);
          if(num > -1 && cnt < 6) {
            pw[idx] = num;
            Serial.println(num);
            idx++;
            cnt++;
          }
        }
      }
    }
   
    // 다음 수신 준비
    irrecv.resume(); 
  }
}
