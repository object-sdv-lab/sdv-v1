#include "SimulationEnvironment.h"

SimulationEnvironment::SimulationEnvironment() :
    start_time_(std::chrono::steady_clock::now()),
    scenario_(nullptr)
{
}

void SimulationEnvironment::set_scenario(IScenario* scenario)
{
    scenario_ = scenario;
}

EnvironmentData SimulationEnvironment::observe(std::string topic) const
{
    if (scenario_ == nullptr)
    {
        return EnvironmentData("");
    }

    auto now_time = std::chrono::steady_clock::now();
    auto elapsed = now_time - start_time_;

    return scenario_->get_data_at(elapsed, topic);
}
