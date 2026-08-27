#pragma once
#include "IController.h"
#include "IEventListener.h"
#include "RainSensorValueChangedEvent.h"
#include "SpeedSensorValueChangedEvent.h"
#include "WiperActuator.h"

class WiperController final :
    public IController,
    public IEventListener<RainSensorValueChangedEvent>,
    public IEventListener<SpeedSensorValueChangedEvent>

{
private:
    int rain_value_ = 0;
    int speed_value_ = 0;
    WiperActuator* wiper_actuator_;

    WiperSpeed calculate_wiper_speed() const;

public:
    explicit WiperController(WiperActuator* wiper_actuator);

    void on_event(const RainSensorValueChangedEvent& event) override;
    void on_event(const SpeedSensorValueChangedEvent& event) override;
};
