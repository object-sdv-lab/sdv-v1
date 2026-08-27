#pragma once
#include "IScenario.h"

class ObstacleDetectionScenario final : public IScenario
{
public:
    // IScenario을(를) 통해 상속됨
    EnvironmentData get_data_at(std::chrono::steady_clock::duration time, std::string topic) override;
};