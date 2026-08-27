#include "RainyDayScenario.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <string>

namespace
{
struct RainyDaySample
{
    int rain;
    int speed;
};

constexpr std::array<RainyDaySample, 6> samples = {
    RainyDaySample{0, 0},
    RainyDaySample{10, 30},
    RainyDaySample{50, 50},
    RainyDaySample{80, 30},
    RainyDaySample{20, 30},
    RainyDaySample{0, 0},
};
}

EnvironmentData RainyDayScenario::get_data_at(
    std::chrono::steady_clock::duration time,
    std::string topic)
{
    const auto elapsed_seconds =
        std::chrono::duration_cast<std::chrono::seconds>(time).count();
    const auto index = static_cast<std::size_t>(std::clamp<long long>(
        elapsed_seconds,
        0,
        static_cast<long long>(samples.size() - 1)));

    if (topic == "rain")
    {
        return EnvironmentData(std::to_string(samples[index].rain));
    }
    if (topic == "speed")
    {
        return EnvironmentData(std::to_string(samples[index].speed));
    }

    return EnvironmentData("");
}
