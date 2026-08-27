#include "TunnelEntryScenario.h"

EnvironmentData TunnelEntryScenario::get_data_at(std::chrono::steady_clock::duration time, std::string topic)
{
    if (topic != "light_intensity")
    {
        return EnvironmentData("");
    }

    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time).count();
    if (seconds >= 10 && seconds < 20)
    {
        return EnvironmentData("10.0"); // 어두운 환경
    }
    else
    {
        return EnvironmentData("100.0"); // 밝은 환경
    }
}
