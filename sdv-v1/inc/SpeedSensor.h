#pragma once
#include "ISensor.h"

class SpeedSensor : public ISensor
{
public:
	void set_value(int value) override;
};