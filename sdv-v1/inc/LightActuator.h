#pragma once
#include "IActuator.h"

class LightActuator : public IActuator
{
public:
	void update(int new_value) override;
	void run() override;
};