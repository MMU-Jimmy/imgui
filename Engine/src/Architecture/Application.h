#pragma once
#include "Window/Window.h"
#include "Macros.h"
#include "EventSystem/Event.h"
#include "EventSystem/EventApplication.h"
#include "EventSystem/EventMouse.h"

class ENGINE_API Application
{
public:
    long const TICKRATE = 100;

    Application();
    virtual ~Application();

    void Run();
    void OnEvent(Event& e);

private:
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;

   // Add more as required
    bool OnWindowClose(Event_WindowClose& e);
    bool OnMouseMove(Event_MouseMoved& e);
    // ..
};

// Implementation @ Project:Client -> Client.cpp
Application* CreateApplication();
