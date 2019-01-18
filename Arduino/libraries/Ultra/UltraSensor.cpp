
#include <Arduino.h>
#include "UltraSensor.h"

UltraSensor::UltraSensor(int trigPin, int echoPin) : m_trigPin(trigPin), m_echoPin(echoPin)
{
	pinMode(m_trigPin, OUTPUT); // 센서 Trig 핀
	pinMode(m_echoPin, INPUT); // 센서 Echo 핀
}

long UltraSensor::getDistance()
{
	digitalWrite(m_trigPin, HIGH); // 센서에 트리거 신호 입력
	delayMicroseconds(10); // 10마이크로초 유지
	digitalWrite(m_trigPin, LOW); // 트리거 신호 유지 off

	// Echo pin : HIGH -> LOW 간격을 측정
	long duration = pulseIn(m_echoPin, HIGH);
	long distance = duration / 58; // 거리(CM)로 변환

	return distance;
}
