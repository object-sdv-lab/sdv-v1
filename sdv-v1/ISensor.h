#pragma once

class ISensor
{
public:
    virtual ~ISensor() = default;

    virtual void sampling() = 0;
};
