#include "WiperController.h"

WiperController::WiperController(vector<IActuator*>& actuator_observer) :
	actuator_observer_(actuator_observer),
	rain_value_(0),
	speed_value_(0),
	effective_rain_(0),
	wiper_speed_(WiperSpeed::OFF)
{};

void WiperController::update(SensorType type, int value) {
	switch (type)
	{
	case SensorType::RAIN:
		rain_value_ = value;
		break;
	case SensorType::SPEED:
		speed_value_ = value;
		break;
	}
}

void WiperController::compute() {
	effective_rain_ = rain_value_ * (1 + speed_value_ / 100);

	if (effective_rain_ >= 0 && effective_rain_ < 5)
	{
		wiper_speed_ = WiperSpeed::OFF;
	}
	else if (effective_rain_ >= 5 && effective_rain_ < 45)
	{
		wiper_speed_ = WiperSpeed::Low;
	}
	else if (effective_rain_ >= 45 && effective_rain_ < 80)
	{
		wiper_speed_ = WiperSpeed::Mid;
	}
	else if (effective_rain_ >= 80)
	{
		wiper_speed_ = WiperSpeed::High;
	}
	else
	{
		wiper_speed_ = WiperSpeed::OFF;
	}

	notify_observer();
}

void WiperController::notify_observer() {
	for (auto observer : actuator_observer_) {
		observer->update(wiper_speed_);
	}
}