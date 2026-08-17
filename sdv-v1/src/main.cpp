#include "SimulationEnvironment.h"
#include "IActuator.h"
#include "IController.h"
#include "ISensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    // environment->set_scenario(scenario);

    std::vector<ISensor*> sensors;
    std::vector<IController*> controllers;
    std::vector<IActuator*> actuators;

    while (true)
    {
        for (ISensor* sensor : sensors)
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