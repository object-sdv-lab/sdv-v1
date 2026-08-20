#pragma once
#include "IEnvironment.h"
#include "IScenario.h"
#include <chrono>

class SimulationEnvironment : public IEnvironment
{
private:
	std::chrono::steady_clock::time_point start_time_;

	IScenario* scenario_;

public:
	SimulationEnvironment();

	void set_scenario(IScenario* scenario);

	// IEnvironment을(를) 통해 상속됨
	EnvironmentData observe(std::string topic) const override;
};
