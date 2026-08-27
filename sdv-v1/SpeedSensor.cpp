#include "SpeedSensor.h"
#include <string>

SpeedSensor::SpeedSensor(const IEnvironment& environment) :
    environment_(environment)
{
}

void SpeedSensor::sampling()
{
    const EnvironmentData data = environment_.observe("speed");
    if (data.value.empty())
    {
        return;
    }

    emit(SensorEvent{SensorType::Speed, std::stoi(data.value)});
}
