#pragma once
#include "IEventListener.h"
#include "IController.h"
#include "Backlight.h"

class BacklightController : public IController, public IEventListener<int>
{
private:
	Backlight* backlight_;
public:
	BacklightController(Backlight* backlight);
	void on_event(const int& event) override;
};

