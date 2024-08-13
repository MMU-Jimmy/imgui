#pragma once

#include "Architecture/Macros.h"
#include <string>
#include <functional>
#include <spdlog/fmt/fmt.h>

enum class EventType
{
    None = 0,
    WindowClose,
    Tick,
    KeyPressed,
    MouseMoved
};

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); }

class ENGINE_API Event
{
    friend class EventDispatcher;

public:
    bool m_Handled = false;

    virtual EventType GetEventType() const = 0;
    virtual const char* GetInfo() const = 0;
    virtual std::string ToString() const { return GetInfo(); }

protected:
    inline bool IsHandled() const { return m_Handled; }
};

class EventDispatcher
{
    template<typename T>
    using EventHandler = std::function<bool(T&)>;

public:
    EventDispatcher(Event& event)
        : m_Event(event)
    {
    }

    template<typename T>
    bool Dispatch(EventHandler<T> handler)
    {
        if (m_Event.GetEventType() == T::GetStaticType())
        {
            m_Event.m_Handled = handler(static_cast<T&>(m_Event));
            return m_Event.m_Handled;
        }
        return false;
    }

private:
    Event& m_Event;
};

