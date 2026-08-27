#pragma once
#include "IEventListener.h"
#include "IController.h"
#include "Airbag.h"

class AirbagController : public IEventListener<int>, public IController
{
private:
	Airbag* airbag_;
public:
	AirbagController(Airbag* airbag);
	void on_event(const int& event) override;
};

