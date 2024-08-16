class EventSDL;

#include "Window/Window.h"
#include "Architecture/Macros.h"
#include "Logging/Console.h"
#include "EventSystem/Event.h"
#include "EventSystem/EventMouse.h"
#include "EventSystem/EventKeyboard.h"
#include "Architecture/Application.h"
#include "EventSystem/EventApplication.h"
#include <iostream>
#include <glad/glad.h>
#include "EventSystem/EventSDL.h"

namespace IonixEngine
{
	Window* Window::Create(const WindowProps& props)
	{
		return new Window(props);
	}

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	void Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		m_Window = SDL_CreateWindow("Engine Name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)props.Width, (int)props.Height, SDL_WINDOW_SHOWN);
		m_Surface = SDL_GetWindowSurface(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

		SDL_FillRect(m_Surface, NULL, SDL_MapRGB(m_Surface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(m_Window);
		SDL_SetWindowData(m_Window, "customData", &m_Data);
	}

	void Window::ShutDown(SDL_Window* window)
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Window::OnUpdate()
	{
		SDL_Event e;
		EventSDL eventSDL;

		while (SDL_PollEvent(&e))
		{
			WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "customData");
			eventSDL.PollEventsSDL(e, data);		
		}
	}
}


