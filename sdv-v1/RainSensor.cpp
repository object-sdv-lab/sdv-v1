#include "RainSensor.h"
#include <string>

RainSensor::RainSensor() :
    environment_(nullptr)
{
}

void RainSensor::set_environment(IEnvironment* environment)
{
    environment_ = environment;
}

void RainSensor::sampling()
{
    if (environment_ == nullptr)
    {
        return;
    }

    const EnvironmentData data = environment_->observe("rain");
    if (data.value.empty())
    {
        return;
    }

    emit(SensorEvent{SensorType::Rain, std::stoi(data.value)});
}
