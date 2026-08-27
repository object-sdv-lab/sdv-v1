#include "SimulationEnvironment.h"
#include "IActuator.h"
#include "IController.h"
#include "ISensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "EmergencyScenario.h"

#include "SpeedSensor.h"
#include "Airbag.h"
#include "AirbagController.h"
#include "Backlight.h"
#include "BacklightController.h"

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    EmergencyScenario* scenario = new EmergencyScenario();
     environment->set_scenario(scenario);

    

    Airbag* airbag = new Airbag();
    AirbagController* airbagController = new AirbagController(airbag);

    Backlight* backlight = new Backlight();
    BacklightController* backlightController = new BacklightController(backlight);

    SpeedSensor* speedSensor = new SpeedSensor();
    speedSensor->set_environment(environment);
    speedSensor->subscribe(airbagController);
    speedSensor->subscribe(backlightController);

    std::vector<ISensor*> sensors = {speedSensor};
    std::vector<IController*> controllers = { airbagController, backlightController };
    std::vector<IActuator*> actuators = { airbag , backlight};

    
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