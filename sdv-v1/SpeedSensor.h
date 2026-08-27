#pragma once
#include "ISensor.h"
#include "EventEmitter.hpp"
#include "IEnvironment.h"

class SpeedSensor : public ISensor, public EventEmitter<int>
{
private:
	int speed_;
	IEnvironment* environment_;
	
public:
	SpeedSensor();
	void set_environment(IEnvironment* environment);
	void sampling() override;
};

