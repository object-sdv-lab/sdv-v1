#include "SpeedSensor.h"

SpeedSensor::SpeedSensor(vector<ISensorObserver*>& sensor_observer) :
	sensor_observer_(sensor_observer),
	speed_value_(0)
{};

void SpeedSensor::set_value(int value) {
	this->speed_value_ = value;
	notify_observer();
}

void SpeedSensor::notify_observer() {
	for (auto observer : this->sensor_observer_) {
		observer->update(speed_value_);
	}
}