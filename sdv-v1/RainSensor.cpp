#include "RainSensor.h"
#include <string>

RainSensor::RainSensor(const IEnvironment& environment) :
    environment_(environment)
{
}

void RainSensor::sampling()
{
    const EnvironmentData data = environment_.observe("rain");
    if (data.value.empty())
    {
        return;
    }

    emit(SensorEvent{SensorType::Rain, std::stoi(data.value)});
}
