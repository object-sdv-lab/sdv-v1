#pragma once
#include "WiperSpeed.h"

class IActuator
{
public: 
	virtual ~IActuator() = default;

	virtual void update(WiperSpeed wiper_speed) = 0;
	virtual void run() = 0;
};

