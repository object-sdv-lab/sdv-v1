#pragma once
#include "ISensor.h"

using namespace std;

class RainSensor : public ISensor
{
private:
	vector<ISensorObserver*> sensor_observer_;
	int rain_value_;

public:
	RainSensor(vector<ISensorObserver*>& sensor_observer);

	void set_value(int value) override;
	void notify_observer() override;
};