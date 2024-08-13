#include "Application.h"
#include "EventSystem/EventApplication.h"
#include "EventSystem/EventMouse.h"
#include "Logging/Console.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL.h>
#include <stdio.h>


#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

Application::Application()
{
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Application::~Application() { }

void Application::OnEvent(Event& e)
{
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<Event_WindowClose>(BIND_EVENT_FN(OnWindowClose));
    dispatcher.Dispatch<Event_MouseMoved>(BIND_EVENT_FN(OnMouseMove));
}

void Application::Run()
{
    m_Running = true;  

    while (m_Running)
    {
        m_Window->OnUpdate();

        Console::GetEngineLogger().info("Game loop");
        std::this_thread::sleep_for(std::chrono::milliseconds(TICKRATE));
    }
}