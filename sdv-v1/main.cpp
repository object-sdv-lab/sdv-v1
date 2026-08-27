#include "IActuator.h"
#include "IController.h"
#include "ISensor.h"
#include "WarningBuzzer.h"
#include "ObstacleWarningController.h"
#include "CameraSensor.h"
#include "SimulationEnvironment.h"
#include "ObstacleDetectionScenario.h"
#include "Headlight.h"
#include "HeadlightController.h"
#include "LightSensor.h"
#include "TunnelEntryScenario.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    IScenario* scenario = new ObstacleDetectionScenario();

    WarningBuzzer* warning_buzzer = new WarningBuzzer();
    ObstacleWarningController* obstacle_warning_controller = new ObstacleWarningController(warning_buzzer);

    CameraSensor* camera_sensor = new CameraSensor();
    LightSensor* light_sensor = new LightSensor();
    Headlight* head_light = new Headlight();
    HeadlightController* head_light_controller = new HeadlightController(head_light);

    environment->set_scenario(scenario);
    camera_sensor->set_environment(environment);
    camera_sensor->subscribe(obstacle_warning_controller);
    light_sensor->set_environment(environment);
    light_sensor->subscribe(head_light_controller);

    std::vector<ISensor*> sensors = { camera_sensor, light_sensor };
    std::vector<IController*> controllers = { obstacle_warning_controller, head_light_controller };
    std::vector<IActuator*> actuators = { warning_buzzer, head_light };

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
