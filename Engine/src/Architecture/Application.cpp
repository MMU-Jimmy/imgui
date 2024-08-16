#include "Application.h"
#include "EventSystem/EventApplication.h"
#include "EventSystem/EventMouse.h"
#include "Logging/Console.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <SDL.h>
#include <stdio.h>
#include "LayerSystem/Layer.h"
#include "LayerSystem/Layers/LayerImGui.h"
#include "LayerSystem/Layers/LayerExample.h"

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace IonixEngine
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

        // Adds a new Layer (ImGui) to the layer-stack, and assigns ID 1 for retrieval
        m_LayerStack.PushLayer(new LayerImGui(1));

        //m_LayerStack.PushLayer(new LayerExample(2)); // and so on...

        // make a scene
        m_objects = new Scene(); // a philosophical point - are we ok using raw pointers? It's a PITA doing anything else, but maybe we could try.
    }

    Application::~Application() { }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<Event_WindowClose>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.Dispatch<Event_MouseMoved>(BIND_EVENT_FN(OnMouseMove));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.m_Handled)
                break;
        }
    }

    void Application::Run()
    {
        m_Running = true;

        while (m_Running)
        {
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();

            Console::GetEngineLogger().info("Game loop");
            std::this_thread::sleep_for(std::chrono::milliseconds(TICKRATE));
        }
    }
}