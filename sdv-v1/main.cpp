#include "Headlight.h"
#include "HeadlightController.h"
#include "IActuator.h"
#include "IController.h"
#include "ISensor.h"
#include "LightSensor.h"
#include "SimulationEnvironment.h"
#include "TunnelEntryScenario.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    TunnelEntryScenario* scenario = new TunnelEntryScenario();
    environment->set_scenario(scenario);

    Headlight* head_light = new Headlight();
    HeadlightController* head_light_controller = new HeadlightController(head_light);

    LightSensor* light_sensor = new LightSensor();
    light_sensor->set_environment(environment);
    light_sensor->subscribe(head_light_controller);

    std::vector<ISensor*> sensors = { light_sensor };
    std::vector<IController*> controllers = { head_light_controller };
    std::vector<IActuator*> actuators = { head_light };

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
