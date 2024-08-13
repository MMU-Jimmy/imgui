#include "EventSystem/EventSDL.h"

void EventSDL::PollEventsSDL(SDL_Event e, Window::WindowData& windowData)
{
	switch (e.type)
	{
	case SDL_WINDOWEVENT_CLOSE:
	{
		Event_WindowClose closeEvent;
		windowData.EventCallback(closeEvent);
		break;
	}

	case SDL_MOUSEMOTION:
	{
		Event_MouseMoved event((double)e.motion.x, (double)e.motion.y);
		windowData.EventCallback(event);
		break;
	}

	default:
		break;	
	}
}
