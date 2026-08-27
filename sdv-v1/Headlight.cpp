#include "Headlight.h"
#include <iostream>

Headlight::Headlight() :
    is_on_(false)
{
}

void Headlight::turn_on()
{
    is_on_ = true;
}

void Headlight::turn_off()
{
    is_on_ = false;
}

void Headlight::run()
{
    if (is_on_)
    {
        std::cout << "Headlight is ON" << std::endl;
    }
    else
    {
        std::cout << "Headlight is OFF" << std::endl;
    }
}
