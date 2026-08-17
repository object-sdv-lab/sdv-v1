#pragma once
#include "IController.h"
#include "IActuator.h"
#include "WiperSpeed.h"
#include <iostream>
#include <vector>

using namespace std;

class WiperController : public IController
{
private:
	int rain_value_;
	int speed_value_;
	int effective_rain_;
	WiperSpeed wiper_speed_;

	vector<IActuator*> actuator_observer_;
public:
	WiperController(vector<IActuator*>& acutator_observer);

	void compute() override;
	void notify_observer() override;
	void update(SensorType type, int value) override;
};

