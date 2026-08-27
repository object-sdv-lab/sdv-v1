#include "SpeedSensor.h"
#include <string>

SpeedSensor::SpeedSensor() : speed_(0), environment_(nullptr) {}

void
SpeedSensor::set_environment(IEnvironment* environment) {
	this->environment_ = environment;
}

void
SpeedSensor::sampling() {
	if (environment_ == nullptr) {
		return;
	}
	speed_ = std::stoi(environment_->observe("speed").value);
	this->emit(speed_);
}