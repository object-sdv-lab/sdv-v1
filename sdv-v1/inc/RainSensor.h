#pragma once
#include "ISensor.h"

class RainSensor : public ISensor
{
private:
	int rain_value_;

public:
	void set_value(int value) override;
	void notify_observer() override;
};