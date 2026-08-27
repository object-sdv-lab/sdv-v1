#pragma once
#include "IActuator.h"
#include "IEventListener.h"
#include "WiperSpeed.h"

class WiperActuator final : public IActuator, public IEventListener<WiperSpeed>
{
private:
    WiperSpeed wiper_speed_ = WiperSpeed::Off;

public:
    void on_event(const WiperSpeed& wiper_speed) override;
    void run() override;
};
