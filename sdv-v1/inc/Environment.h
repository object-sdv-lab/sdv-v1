#pragma once
class IEnvironment
{
public:
	virtual ~IEnvironment() = default;

	virtual int now_value() = 0;
};

