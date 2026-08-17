#pragma once
#include "ISensor.h"

class RainSensor : public ISensor
{
public:
	void set_value(int value) override;
};