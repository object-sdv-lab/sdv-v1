#include "WiperActuator.h"
#include <iostream>

void WiperActuator::on_event(const WiperSpeed& wiper_speed)
{
    wiper_speed_ = wiper_speed;
}

void WiperActuator::run()
{
    switch (wiper_speed_)
    {
    case WiperSpeed::Off:
        std::cout << "Wiper state: OFF\n";
        break;
    case WiperSpeed::Low:
        std::cout << "Wiper state: Move low speed\n";
        break;
    case WiperSpeed::Medium:
        std::cout << "Wiper state: Move middle speed\n";
        break;
    case WiperSpeed::High:
        std::cout << "Wiper state: Move high speed\n";
        break;
    }
}
