#pragma once
#include "IActuator.h"

class WiperActuator : public IActuator
{
public:
	void update(int new_value) override;
	void run() override;
};