#include "WarningBuzzer.h"
#include "ObstacleWarningController.h"
#include "IActuator.h"
#include "IController.h"
#include "ISensor.h"
#include "CameraSensor.h"
#include "SimulationEnvironment.h"
#include "ObstacleDetectionScenario.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    ObstacleDetectionScenario* scenario = new ObstacleDetectionScenario();
    environment->set_scenario(scenario);

    WarningBuzzer* warning_buzzer = new WarningBuzzer();
    ObstacleWarningController* obstacle_warning_controller = new ObstacleWarningController(warning_buzzer);

    CameraSensor* camera_sensor = new CameraSensor();
    camera_sensor->set_environment(environment);
    camera_sensor->subscribe(obstacle_warning_controller);

    std::vector<ISensor*> sensors = { camera_sensor };
    std::vector<IController*> controllers = { obstacle_warning_controller };
    std::vector<IActuator*> actuators = { warning_buzzer };

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
