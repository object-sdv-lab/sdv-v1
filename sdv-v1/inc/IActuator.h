#pragma once
class IActuator
{
public: 
	virtual ~IActuator() = default;

	virtual void update(int new_value) = 0;
	virtual void run() = 0;
};

