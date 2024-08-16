#pragma once

#include "EventSystem/Event.h"
#include <sstream>
#include "Logging/Console.h"

namespace IonixEngine
{
    class Event_MouseMoved : public Event
    {
    public:
        EVENT_CLASS_TYPE(MouseMoved)

            Event_MouseMoved(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        virtual const char* GetInfo() const override
        {
            m_CachedName = std::string("MouseMovedEvent: X=") + std::to_string(m_MouseX) + 
                ", Y=" + std::to_string(m_MouseY);
        
            Console::GetEngineLogger().info(m_CachedName);
            return m_CachedName.c_str();
        }


    private:
        float m_MouseX, m_MouseY;
        mutable std::string m_CachedName;
    };
}


