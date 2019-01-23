#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "WiFiUtil.h"

SoftwareSerial softSerial(2, 3);

char ssid[] = "MULTI_GUEST"; // 네트워크 SSID
char pass[] = "guest1357"; // 비밀번호
char server[] = "70.12.112.142"; // 서버 IP

// WiFi 클라이언트 객체 초기화
WiFiEspClient client;

void setup() {
  wifi_init(ssid, pass);
}

void loop() {
  Serial.println();
  Serial.println("Starting connection to server...");
  
  // Echo 서버 연결
  if (client.connect(server, 9999)) {
    Serial.println("Connected to server");
    delay(5000);
    
    int cdsValue = analogRead(A0); // 조도 센서
    float tmpValue = ((analogRead(A5) * 5.0 / 1024.0) - 0.5) * 100; // 온도 센서
    
    Serial.print("cds = "); 
    Serial.print(cdsValue);
    Serial.print(", tmp = "); 
    Serial.println(tmpValue);
    
    client.print("조도 값 : "); // 메시지 전송
    client.print(cdsValue);
    client.print(", 온도 값 : ");
    client.println(tmpValue);
  }

  // 메시지 수신
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  delay(3000);
}
