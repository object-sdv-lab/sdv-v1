#pragma once
#include "IScenario.h"

class EmergencyScenario : public IScenario
{
public:
	EnvironmentData get_data_at(std::chrono::steady_clock::duration time, std::string topic) override;
};

