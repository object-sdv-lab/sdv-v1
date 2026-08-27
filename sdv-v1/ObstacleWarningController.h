#pragma once
#include "IController.h"
#include "IEventListener.h"
#include "ObstacleDistanceChangedEvent.h"
#include "WarningBuzzer.h"

class ObstacleWarningController final : public IController, public IEventListener<ObstacleDistanceChangedEvent>
{
private:
    WarningBuzzer* warning_buzzer_;

public:
    ObstacleWarningController(WarningBuzzer* warning_buzzer);

    // IEventListener<ObstacleDistanceChangedEvent>을(를) 통해 상속됨
    void on_event(const ObstacleDistanceChangedEvent& event) override;
};