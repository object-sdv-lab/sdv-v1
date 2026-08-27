#include "SpeedSensor.h"
#include <string>

SpeedSensor::SpeedSensor() :
    environment_(nullptr)
{
}

void SpeedSensor::set_environment(IEnvironment* environment)
{
    environment_ = environment;
}

void SpeedSensor::sampling()
{
    if (environment_ == nullptr)
    {
        return;
    }

    const EnvironmentData data = environment_->observe("speed");
    if (data.value.empty())
    {
        return;
    }

    emit(SpeedSensorValueChangedEvent{std::stoi(data.value)});
}
