#include "LightSensor.h"

LightSensor::LightSensor() :
    light_intensity_(0.0),
    environment_(nullptr)
{
}

void LightSensor::set_environment(IEnvironment* environment)
{
    environment_ = environment;
}

void LightSensor::sampling()
{
    if (environment_ == nullptr)
    {
        return;
    }

    try
    {
        light_intensity_ = std::stod(environment_->observe("light_intensity").value);
        emit(LightIntensityChangedEvent(light_intensity_));
    }
    catch (...)
    {
    }
}
