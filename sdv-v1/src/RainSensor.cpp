#include "RainSensor.h"

RainSensor::RainSensor(vector<ISensorObserver*>& sensor_observer) :
	sensor_observer_(sensor_observer),
	rain_value_(0)
{};

void RainSensor::set_value(int value) {
	this->rain_value_ = value;
	notify_observer();
}

void RainSensor::notify_observer() {
	for (auto observer : this->sensor_observer_) {
		observer->update(rain_value_);
	}
}