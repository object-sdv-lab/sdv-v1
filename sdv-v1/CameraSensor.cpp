#include "CameraSensor.h"

CameraSensor::CameraSensor() :
    distance_(0.0),
    environment_(nullptr)
{
}

void CameraSensor::set_environment(IEnvironment* environment)
{
    environment_ = environment;
}

void CameraSensor::sampling()
{
    if(environment_ == nullptr)
    {
        return;
    }

    distance_ = std::stod(environment_->observe("obstacle_distance").value);
    emit(ObstacleDistanceChangedEvent(distance_));
}
