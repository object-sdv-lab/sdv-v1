#pragma once
#include "ISensorObserver.h"
#include "IActuatorSubject.h"

class IController : public ISensorObserver, public IActuatorSubject
{
public:
	virtual ~IController() = default;
};

