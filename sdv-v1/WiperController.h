#pragma once
#include "EventEmitter.hpp"
#include "IController.h"
#include "IEventListener.h"
#include "SensorEvent.h"
#include "WiperSpeed.h"

class WiperController final :
    public IController,
    public IEventListener<SensorEvent>,
    public EventEmitter<WiperSpeed>
{
private:
    int rain_value_ = 0;
    int speed_value_ = 0;

    WiperSpeed calculate_wiper_speed() const;

public:
    void on_event(const SensorEvent& event) override;
};
