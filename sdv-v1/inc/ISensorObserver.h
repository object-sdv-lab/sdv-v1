#pragma once
#include "SensorType.h"

class ISensorObserver
{
public:
	virtual ~ISensorObserver() = default;

	virtual void update(SensorType type, int value) = 0;
};

