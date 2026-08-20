#pragma once
#include "EnvironmentData.h"
#include <chrono>

class IScenario
{
public:
	virtual ~IScenario() = default;

	virtual EnvironmentData get_data_at(std::chrono::steady_clock::duration time, std::string topic) = 0;
};
