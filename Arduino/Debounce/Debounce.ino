const int buttonPin = 2;
const int ledPin = 13;

int ledState = HIGH; // 현재 출력LED 상태
int buttonState; // 현재 버튼 상태
int lastButtonState = LOW; // 이전 버튼 상태

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // 측정 지연시간

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if(reading != lastButtonState) { // 이전상태와 달라짐, 시간 측정
    lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > debounceDelay) { // 지연 시간 이내의 변화라면 무시
    if(reading != buttonState) {
      buttonState = reading;
      if(buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);

  lastButtonState = reading;
}
