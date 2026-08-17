#pragma once
#include "ISensor.h"

class SpeedSensor : public ISensor
{
private:
	int speed_value_;

public:
	void set_value(int value) override;
	void notify_observer() override;
};