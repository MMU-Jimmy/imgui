#pragma once
#include "EventSystem/EventApplication.h"
#include "EventSystem/EventMouse.h"
#include "Window/Window.h"
#include "SDL.h"

class EventSDL
{
public:
    EventSDL() { }
    ~EventSDL() { }

    void PollEventsSDL(SDL_Event e, Window::WindowData& windowData);
};