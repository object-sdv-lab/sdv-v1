#include "EmergencyScenario.h"

EnvironmentData
EmergencyScenario::get_data_at(std::chrono::steady_clock::duration time, std::string topic) {
    if (topic != "speed")
    {
        return EnvironmentData("");
    }

    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time).count();
    if (seconds >= 10)
    {
        return EnvironmentData("0"); // speed = 0
    }
    else
    {
        return EnvironmentData("100.0"); // speed = 100
    }
}