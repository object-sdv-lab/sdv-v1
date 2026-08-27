#include "WiperController.h"

WiperController::WiperController(WiperActuator* wiper_actuator) :
    wiper_actuator_(wiper_actuator)
{
}

void WiperController::on_event(const RainSensorValueChangedEvent& event)
{
    rain_value_ = event.rain_value_;
    wiper_actuator_->set_speed(calculate_wiper_speed());
}

void WiperController::on_event(const SpeedSensorValueChangedEvent& event)
{
    speed_value_ = event.speed_value_;
    wiper_actuator_->set_speed(calculate_wiper_speed());
}

WiperSpeed WiperController::calculate_wiper_speed() const
{
    const int effective_rain = rain_value_ * (100 + speed_value_) / 100;

    if (effective_rain < 5)
    {
        return WiperSpeed::Off;
    }
    if (effective_rain < 45)
    {
        return WiperSpeed::Low;
    }
    if (effective_rain < 80)
    {
        return WiperSpeed::Medium;
    }

    return WiperSpeed::High;
}
