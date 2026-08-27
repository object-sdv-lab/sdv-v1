#include "ObstacleDetectionScenario.h"

EnvironmentData ObstacleDetectionScenario::get_data_at(std::chrono::steady_clock::duration time, std::string topic)
{
    if (topic != "obstacle_distance")
    {
        return EnvironmentData("");
    }

    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time).count();

    if (seconds < 5)
    {
        return EnvironmentData("10.0");
    }
    else if (seconds < 10)
    {
        return EnvironmentData("4.0");
    }
    else if (seconds < 15)
    {
        return EnvironmentData("1.5");
    }

    return EnvironmentData("10.0");
}