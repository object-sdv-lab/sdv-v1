#include "RainSensor.h"
#include "RainyDayScenario.h"
#include "SimulationEnvironment.h"
#include "SpeedSensor.h"
#include "WiperActuator.h"
#include "WiperController.h"
#include <chrono>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main()
{
    SimulationEnvironment* environment = new SimulationEnvironment();
    RainyDayScenario* scenario = new RainyDayScenario();
    environment->set_scenario(scenario);

    WiperActuator* wiper_actuator = new WiperActuator();
    WiperController* wiper_controller = new WiperController(wiper_actuator);

    RainSensor* rain_sensor = new RainSensor();
    rain_sensor->set_environment(environment);
    rain_sensor->subscribe(wiper_controller);

    SpeedSensor* speed_sensor = new SpeedSensor();
    speed_sensor->set_environment(environment);
    speed_sensor->subscribe(wiper_controller);

    std::vector<ISensor*> sensors = {rain_sensor, speed_sensor};
    std::vector<IController*> controllers = {wiper_controller};
    std::vector<IActuator*> actuators = {wiper_actuator};

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
