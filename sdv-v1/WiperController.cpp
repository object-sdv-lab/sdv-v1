#include "WiperController.h"

void WiperController::on_event(const SensorEvent& event)
{
    switch (event.type)
    {
    case SensorType::Rain:
        rain_value_ = event.value;
        break;
    case SensorType::Speed:
        speed_value_ = event.value;
        break;
    }

    emit(calculate_wiper_speed());
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
