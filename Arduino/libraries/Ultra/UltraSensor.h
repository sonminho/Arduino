#ifndef _ULTRASENSOR_h
#define _ULTRASENSOR_h

class UltraSensor
{
 protected:
	 int m_trigPin;
	 int m_echoPin;

 public:
	 UltraSensor(int trigPin, int echoPin);
	 long getDistance();
};

#endif