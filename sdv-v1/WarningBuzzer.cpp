#include "WarningBuzzer.h"
#include <iostream>

WarningBuzzer::WarningBuzzer()
    : level_(WarningLevel::SAFE)
{
}

void WarningBuzzer::set_level(WarningLevel level)
{
    level_ = level;
}

void WarningBuzzer::run()
{
    switch(level_)
    {
    case WarningLevel::SAFE:
        std::cout << "Warning buzzer is OFF" << std::endl;
        break;
    case WarningLevel::CAUTION:
        std::cout << "Beep... Beep..." << std::endl;
        break;
    case WarningLevel::DANGER:
        std::cout << "BEEEEEP!!!" << std::endl;
        break;
    }

}
