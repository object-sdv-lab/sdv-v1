#pragma once
class IActuatorSubject
{
public:
	virtual ~IActuatorSubject() = default;

	virtual void notify_observer() = 0;
	virtual void update(int new_value) = 0;
};

