#pragma once
#include "IActuator.h"
class Backlight : public IActuator
{
private:
	bool is_on_;
public:
	Backlight();
	void turn_on();
	void turn_off();
	void run() override;
};

