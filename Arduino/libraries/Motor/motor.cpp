#include <Arduino.h>
#include "motor.h"

Motor::Motor(int motorA1, int motorA2, int motorAs, int motorB1, int motorB2, int motorBs)
{
	m_motor_A1 = motorA1;
	m_motor_A2 = motorA2;
	m_motor_As = motorAs;
	m_motor_B1 = motorB1;
	m_motor_B2 = motorB2;
	m_motor_Bs = motorBs;

	pinMode(m_motor_A1, OUTPUT);
	pinMode(m_motor_A2, OUTPUT);
	pinMode(m_motor_As, OUTPUT);
	pinMode(m_motor_B1, OUTPUT);
	pinMode(m_motor_B2, OUTPUT);
	pinMode(m_motor_Bs, OUTPUT);
}

void Motor::forward(int speed)
{
	digitalWrite(m_motor_A1, LOW);
	digitalWrite(m_motor_A2, HIGH);
	analogWrite(m_motor_As, speed);
	digitalWrite(m_motor_B1, LOW);
	digitalWrite(m_motor_B2, HIGH);
	analogWrite(m_motor_Bs, speed);
}

void Motor::back(int speed)
{
	digitalWrite(m_motor_A1, HIGH);
	digitalWrite(m_motor_A2, LOW);
	analogWrite(m_motor_As, speed);
	digitalWrite(m_motor_B1, HIGH);
	digitalWrite(m_motor_B2, LOW);
	analogWrite(m_motor_Bs, speed);
}

void Motor::turnLeft(int speed)
{
	digitalWrite(m_motor_A1, LOW);
	digitalWrite(m_motor_A2, LOW);
	analogWrite(m_motor_As, 0);
	digitalWrite(m_motor_B1, LOW);
	digitalWrite(m_motor_B2, HIGH);
	analogWrite(m_motor_Bs, speed);
}

void Motor::turnRight(int speed)
{
	digitalWrite(m_motor_A1, LOW);
	digitalWrite(m_motor_A2, HIGH);
	analogWrite(m_motor_As, speed);
	digitalWrite(m_motor_B1, LOW);
	digitalWrite(m_motor_B2, LOW);
	analogWrite(m_motor_Bs, 0);
}

void Motor::stop()
{
	digitalWrite(m_motor_A1, LOW);
	digitalWrite(m_motor_A2, LOW);
	analogWrite(m_motor_As, 0);
	digitalWrite(m_motor_B1, LOW);
	digitalWrite(m_motor_B2, LOW);
	analogWrite(m_motor_Bs, 0);
}
