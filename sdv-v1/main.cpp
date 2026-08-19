#include "IActuator.h"
#include "IController.h"
#include "Sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    IEnvironment* environment = nullptr;
    std::vector<Sensor*> sensors;
    std::vector<IController*> controllers;
    std::vector<IActuator*> actuators;

    while (true)
    {
        for (Sensor* sensor : sensors)
        {
            sensor->sampling();
        }
        for (IActuator* actuator : actuators)
        {
            actuator->run();
        }

        std::this_thread::sleep_for(1s);
    }
}