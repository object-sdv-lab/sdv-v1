#pragma once
#include "IActuator.h"
#include "WiperSpeed.h"

class WiperActuator final : public IActuator
{
private:
    WiperSpeed wiper_speed_ = WiperSpeed::Off;

public:
    void set_speed(WiperSpeed wiper_speed);
    void run() override;
};
