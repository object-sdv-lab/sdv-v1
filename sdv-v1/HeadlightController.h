#pragma once
#include "IController.h"
#include "IEventListener.h"
#include "LightIntensityChangedEvent.h"
#include "Headlight.h"

class HeadlightController final : public IController, public IEventListener<LightIntensityChangedEvent>
{
private:
    Headlight* head_light_;

public:
    HeadlightController(Headlight* head_light);

    // IEventListener<LightIntensityChangedEvent>을(를) 통해 상속됨
    void on_event(const LightIntensityChangedEvent& event) override;
};
