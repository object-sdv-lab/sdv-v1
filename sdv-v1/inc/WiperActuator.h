#pragma once
#include "IActuator.h"

class WiperActuator : public IActuator
{
private:
	WiperSpeed wiper_speed_;

public:
	WiperActuator();

	void update(WiperSpeed wiper_speed) override;
	void run() override;
};