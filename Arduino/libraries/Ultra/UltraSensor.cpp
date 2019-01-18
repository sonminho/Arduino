
#include <Arduino.h>
#include "UltraSensor.h"

UltraSensor::UltraSensor(int trigPin, int echoPin) : m_trigPin(trigPin), m_echoPin(echoPin)
{
	pinMode(m_trigPin, OUTPUT); // ���� Trig ��
	pinMode(m_echoPin, INPUT); // ���� Echo ��
}

long UltraSensor::getDistance()
{
	digitalWrite(m_trigPin, HIGH); // ������ Ʈ���� ��ȣ �Է�
	delayMicroseconds(10); // 10����ũ���� ����
	digitalWrite(m_trigPin, LOW); // Ʈ���� ��ȣ ���� off

	// Echo pin : HIGH -> LOW ������ ����
	long duration = pulseIn(m_echoPin, HIGH);
	long distance = duration / 58; // �Ÿ�(CM)�� ��ȯ

	return distance;
}
