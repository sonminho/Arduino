#ifndef _MOTOR_H
#define _MOTOR_H

class Motor {
private:
	int m_motor_A1;
	int m_motor_A2;
	int m_motor_As;
	int m_motor_B1;
	int m_motor_B2;
	int m_motor_Bs;
public:
	Motor(int motorA1, int motorA2, int motorAs, int motorB1, int motorB2, int motorBs);
	void forward(int speed);
	void back(int speed);
	void turnLeft(int speed);
	void turnRight(int speed);
	void stop();
};

#endif // !_MOTOR_H