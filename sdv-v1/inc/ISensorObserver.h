#pragma once
class ISensorObserver
{
public:
	virtual ~ISensorObserver() = default;

	virtual int compute() = 0;
	virtual void notify_observer() = 0;
};

