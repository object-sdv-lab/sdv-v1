#pragma once
#include "IEventListener.h"
#include "ISensorEvent.h"

class IController : public IEventListener<ISensorEvent>
{
public:
    virtual ~IController() = default;
};
