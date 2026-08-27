#pragma once
#include "EventEmitter.hpp"
#include "IEnvironment.h"
#include "ISensor.h"
#include "RainSensorValueChangedEvent.h"

class RainSensor final : public ISensor, public EventEmitter<RainSensorValueChangedEvent>
{
private:
    IEnvironment* environment_;

public:
    RainSensor();

    void set_environment(IEnvironment* environment);

    void sampling() override;
};
