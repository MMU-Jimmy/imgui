#pragma once

#include "EventSystem/Event.h"
#include <sstream>

namespace IonixEngine
{
    class EventKey : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

    protected:
        EventKey(int keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };
}
