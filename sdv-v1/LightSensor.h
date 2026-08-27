#pragma once
#include "ISensor.h"
#include "IEnvironment.h"
#include "EventEmitter.hpp"
#include "LightIntensityChangedEvent.h"

class LightSensor final : public ISensor, public EventEmitter<LightIntensityChangedEvent>
{
private:
    double light_intensity_;
    IEnvironment* environment_;

public:
    LightSensor();

    void set_environment(IEnvironment* environment);

    // ISensor을(를) 통해 상속됨
    void sampling() override;
};
