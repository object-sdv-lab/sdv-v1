#pragma once
#include "EnvironmentData.h"

class IEnvironment
{
public:
	virtual ~IEnvironment() = default;  

	virtual EnvironmentData observe(std::string topic) const = 0;
};
