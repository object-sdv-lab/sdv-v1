#pragma once
#include "IController.h"
#include <iostream>
#include <vector>

class ISensor
{
public:
	virtual ~ISensor() = default;

	virtual void set_value(int value) = 0;
	virtual void notify_observer() = 0;
};

