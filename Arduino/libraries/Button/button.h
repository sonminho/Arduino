#ifndef BUTTON_H
#define BUTTON_H

#define UP_EDGE HIGH
#define DOWN_EDGE LOW

typedef void(*fn_p)();
typedef void(*fni_p)(int);

class Button {
private:
	const int m_pin;
	int m_mode;
	int m_buttonState;
	int m_lastButtonState = LOW;
	unsigned long m_lastDebounceTime = 0;
	fn_p m_click;
public:
	Button(int pin);
	Button(int pin, fn_p click, int mode = UP_EDGE);
	void check();
	int read();
	int read(fni_p click);
};
#endif