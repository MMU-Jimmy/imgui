#pragma once

#include "Application.h"
#include "Logging/Console.h"

Application::Application() { }

Application::~Application() { }

// temp
long tickrate = 600;

void Application::Run()
{
	while (m_Running)
	{
		Console::GetEngineLogger().info("Game loop");
		std::this_thread::sleep_for(std::chrono::milliseconds(tickrate));
	}
}

