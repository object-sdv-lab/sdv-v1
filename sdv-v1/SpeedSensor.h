#pragma once
#include "EventEmitter.hpp"
#include "IEnvironment.h"
#include "ISensor.h"
#include "SensorEvent.h"

class SpeedSensor final : public ISensor, public EventEmitter<SensorEvent>
{
private:
    const IEnvironment& environment_;

public:
    explicit SpeedSensor(const IEnvironment& environment);

    void sampling() override;
};
