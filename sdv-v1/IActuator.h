#pragma once

class IActuator
{
public:
    virtual ~IActuator() = default;

    virtual void run() const = 0;
};
