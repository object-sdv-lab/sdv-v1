#pragma once
#include "SensorType.h"

struct SensorValueChangedEvent
{
    SensorType type;
    int value;
};
