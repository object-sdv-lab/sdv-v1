#pragma once
#include "EventEmitter.hpp"
#include "IEnvironment.h"
#include "ISensorEvent.h"

class Sensor : public EventEmitter<ISensorEvent>
{
private:
    IEnvironment* environment_;

public:
    Sensor();
    virtual ~Sensor() = default;

    void set_environment(IEnvironment* environment);

protected:
    IEnvironment* get_environment() const;

public:
    virtual void sampling() = 0;
};