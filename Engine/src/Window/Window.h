#pragma once
#include <string>>
#include "Architecture/Macros.h"
#include "EventSystem/Event.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>

struct WindowProps
{
	std::string Title;
	unsigned int Width;
	unsigned int Height;

	WindowProps(const std::string& title = "Engine Name",
		unsigned int width = 1280,
		unsigned int height = 720)
		: Title(title), Width(width), Height(height)
	{
	}
};
class ENGINE_API Window
{
public:

	using EventCallbackFn = std::function<void(Event&)>;

	~Window() {}
	Window(const WindowProps& props);

	void OnUpdate();

	inline unsigned int GetWidth() const { return m_Data.Width; }
	inline unsigned int GetHeight() const { return m_Data.Height; }

	inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

	static Window* Create(const WindowProps& props = WindowProps());

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;

		EventCallbackFn EventCallback;
	};

private:
	virtual void Init(const WindowProps& props);
	virtual void ShutDown(SDL_Window* window);

	SDL_Window* m_Window;
	SDL_Surface* m_Surface;

	WindowData m_Data;
};