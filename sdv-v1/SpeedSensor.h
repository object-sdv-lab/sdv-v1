#pragma once
#include "EventEmitter.hpp"
#include "IEnvironment.h"
#include "ISensor.h"
#include "SensorEvent.h"

class SpeedSensor final : public ISensor, public EventEmitter<SensorEvent>
{
private:
    IEnvironment* environment_;

public:
    SpeedSensor();

    void set_environment(IEnvironment* environment);

    void sampling() override;
};
