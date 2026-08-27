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
    RainyDayScenario scenario;
    SimulationEnvironment environment;
    environment.set_scenario(&scenario);

    RainSensor rain_sensor(environment);
    SpeedSensor speed_sensor(environment);
    WiperController wiper_controller;
    WiperActuator wiper_actuator;

    rain_sensor.subscribe(&wiper_controller);
    speed_sensor.subscribe(&wiper_controller);
    wiper_controller.subscribe(&wiper_actuator);

    std::vector<ISensor*> sensors{&rain_sensor, &speed_sensor};
    std::vector<IActuator*> actuators{&wiper_actuator};

    for (int step = 0; step < 10; ++step)
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

    return 0;
}
