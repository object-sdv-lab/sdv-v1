#pragma once

template <typename Event>
class IEventListener
{
public:
    virtual ~IEventListener() = default;
    virtual void on_event(const Event& event) = 0;
};
