#pragma once
#include "EventEmitter.hpp"
#include "IEnvironment.h"
#include "ISensor.h"
#include "SpeedSensorValueChangedEvent.h"

class SpeedSensor final : public ISensor, public EventEmitter<SpeedSensorValueChangedEvent>
{
private:
    IEnvironment* environment_;

public:
    SpeedSensor();

    void set_environment(IEnvironment* environment);

    void sampling() override;
};
