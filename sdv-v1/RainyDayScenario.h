#pragma once
#include "IScenario.h"

class RainyDayScenario final : public IScenario
{
public:
    EnvironmentData get_data_at(
        std::chrono::steady_clock::duration time,
        std::string topic) override;
};
