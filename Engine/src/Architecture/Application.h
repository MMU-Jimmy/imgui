#pragma once
#include "Window/Window.h"
#include "Macros.h"
#include "EventSystem/Event.h"
#include "EventSystem/EventApplication.h"
#include "EventSystem/EventMouse.h"
#include "LayerSystem/LayerStack.h"
#include "Objects/Scene.h"

namespace IonixEngine
{
    class ENGINE_API Application
    {
    public:
        long const TICKRATE = 100; // 10 fps?  

        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        bool OnWindowClose(Event_WindowClose& e);
        bool OnMouseMove(Event_MouseMoved& e);
        // ..

        // is this where we put the 'engine'? i.e. top level objects for each of the systems (objects, physics, scripting etc).
        // or should we have a separate Engine object?
        Scene* m_objects;

    };

    // Implementation @ Project:Client -> Client.cpp
    Application* CreateApplication();
}