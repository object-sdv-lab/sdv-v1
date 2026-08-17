#pragma once
#include "ISensor.h"

using namespace std;

class SpeedSensor : public ISensor
{
private:
	vector<ISensorObserver*> sensor_observer_;
	int speed_value_;

public:
	SpeedSensor(vector<ISensorObserver*>& sensor_observer);

	void set_value(int value) override;
	void notify_observer() override;
};