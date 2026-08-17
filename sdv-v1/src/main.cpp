#include <iostream>
#include <vector>
#include "main.h"

using namespace std;

int main()
{
    vector<IActuator*> actuators;
    vector<IController*> controllers;

    IActuator* wiper = new WiperActuator();
    actuators.push_back(wiper);

    IController* wiper_controller = new WiperController(actuators);
    controllers.push_back(wiper_controller);

    ISensor* rain_sensor = new RainSensor(controllers);
    ISensor* speed_sensor = new SpeedSensor(controllers);

    while (true)
    {
        rain_sensor->set_value(env->now_rain());
        speed_sensor->set_value(env->now_speed());

        for (auto controller : controllers) {
            controller->compute();
        }
        //dealy(1s);
    }
}
