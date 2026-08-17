#pragma once
#include "IController.h"
class WiperController : public IController
{
public:
	int compute() override;
	void notify_observer() override;
	void update(int new_value) override;
};

