#ifndef _WIFI_UTIL_H
#define _WIFI_UTIL_H

// WiFi 연결 함수
// 매개변수 SSID와 비밀번호
void wifi_init(char *ssid, char *password);
// WiFi 연결 상태 출력 함수
void printWifiStatus();

#endif _WIFI_UTIL_H
