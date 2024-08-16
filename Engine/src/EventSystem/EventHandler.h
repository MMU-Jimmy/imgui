#pragma once
#include "Architecture/Application.h"
#include "EventSystem/EventMouse.h"
#include <iostream>

namespace IonixEngine
{
    bool Application::OnWindowClose(Event_WindowClose& e)
    {
        std::cout << "Engine Closed." << std::endl;
        m_Running = false;
        return true;
    }
    bool Application::OnMouseMove(Event_MouseMoved& e)
    {
        Console::GetEngineLogger().info(e.GetInfo());
        return true;
    }
}

