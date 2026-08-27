#pragma once
#include "IActuator.h"

class Headlight final : public IActuator
{
private:
    bool is_on_;

public:
    Headlight();

    void turn_on();
    void turn_off();

    void run() override;
};
