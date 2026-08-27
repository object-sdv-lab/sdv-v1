#include "ObstacleWarningController.h"

ObstacleWarningController::ObstacleWarningController(WarningBuzzer* warning_buzzer) :
    warning_buzzer_(warning_buzzer)
{
}

void ObstacleWarningController::on_event(const ObstacleDistanceChangedEvent& event)
{
    if(event.distance > 5.0)
    {
        warning_buzzer_->set_level(WarningLevel::SAFE);
    }
    else if(event.distance > 2.0)
    {
        warning_buzzer_->set_level(WarningLevel::CAUTION);
    }
    else
    {
        warning_buzzer_->set_level(WarningLevel::DANGER);
    }
}
