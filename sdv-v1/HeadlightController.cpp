#include "HeadlightController.h"

HeadlightController::HeadlightController(Headlight* head_light) :
    head_light_(head_light)
{
}

void HeadlightController::on_event(const LightIntensityChangedEvent& event)
{
    if (event.light_intensity < 20.0)
    {
        head_light_->turn_on();
    }
    else
    {
        head_light_->turn_off();
    }
}
