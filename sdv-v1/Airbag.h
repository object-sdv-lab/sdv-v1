#pragma once
#include "IActuator.h"
class Airbag : public IActuator
{
private:
	bool is_activate_;
public:
	Airbag();
	void activate();
	void run() override;
};

