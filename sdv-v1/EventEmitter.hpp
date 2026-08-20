#pragma once
#include "IEventListener.h"
#include <algorithm>
#include <vector>

template <typename Event>
class EventEmitter
{
private:
    using Listener = IEventListener<Event>;

    std::vector<Listener*> listeners_;

public:
    virtual ~EventEmitter() = default;

    void subscribe(Listener* listener)
    {
        if (std::find(listeners_.begin(), listeners_.end(), listener) != listeners_.end())
        {
            return; // 리스너가 이미 등록됨
        }

        listeners_.push_back(listener);
    }

    void unsubscribe(Listener* listener)
    {
        std::erase(listeners_, listener);
    }

protected:
    void emit(const Event& event) const
    {
        for (auto* listener : listeners_)
        {
            listener->on_event(event);
        }
    }
};
