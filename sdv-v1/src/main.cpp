#include <iostream>
#include <vector>
#include "main.h"
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    IEnvironment* rain_env = new RainEnvironment();

    vector<IActuator*> actuators;
    vector<IController*> controllers;
    vector<ISensorObserver*> sensor_observers;

    IActuator* wiper = new WiperActuator();
    actuators.push_back(wiper);

    IController* wiper_controller = new WiperController(actuators);
    controllers.push_back(wiper_controller);
    sensor_observers.push_back(wiper_controller);

    ISensor* rain_sensor = new RainSensor(sensor_observers);
    ISensor* speed_sensor = new SpeedSensor(sensor_observers);

    Data now_data;
    int idx = 0;
    while (true)
    {
        now_data = rain_env->now_value(idx);

        rain_sensor->set_value(now_data.rain_data);
        speed_sensor->set_value(now_data.speed_data);

        for (auto controller : controllers) {
            controller->compute();
        }
        this_thread::sleep_for(chrono::seconds(1));
        idx++;
        if (idx >= 10) break;
    }
    return 0;
}
