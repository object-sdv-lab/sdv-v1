#pragma once
#include "ISensor.h"
#include "IEnvironment.h"
#include "EventEmitter.hpp"
#include "ObstacleDistanceChangedEvent.h"

class CameraSensor final : public ISensor, public EventEmitter<ObstacleDistanceChangedEvent>
{
private:
    double distance_;
    IEnvironment* environment_;

public:
    CameraSensor();

    void set_environment(IEnvironment* environment);

    // ISensor을(를) 통해 상속됨
    void sampling() override;
};