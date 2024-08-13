#pragma once

#include <sstream>
#include "EventSystem/Event.h"

class Event_WindowClose : public Event
{
public:
    Event_WindowClose() {}

    EVENT_CLASS_TYPE(WindowClose)

    virtual const char* GetInfo() const override
    {
        return "WindowCloseEvent";
    }
};

class Event_Tick : public Event
{
public:
    EVENT_CLASS_TYPE(Tick)
    Event_Tick() {}

    virtual const char* GetInfo() const override
    {
        return "TickEvent";
    }
};