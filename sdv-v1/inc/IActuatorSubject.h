#pragma once
class IActuatorSubject
{
public:
	virtual ~IActuatorSubject() = default;

	virtual void update(int new_value) = 0;
};

