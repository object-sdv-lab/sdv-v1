#pragma once
class ISensorObserver
{
public:
	virtual ~ISensorObserver() = default;

	virtual void update(int new_value) = 0;
};

