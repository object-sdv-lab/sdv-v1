#pragma once
#include "IActuator.h"

enum class WarningLevel
{
    SAFE,
    CAUTION,
    DANGER
};

class WarningBuzzer final : public IActuator
{
private:
    // bool is_on_;
    WarningLevel level_;

public:
    WarningBuzzer();

    void set_level(WarningLevel level);

    void run() override;
};