#pragma once
#define SDL_MAIN_HANDLED
#include "SDL/SDL_INIT.h"

#include "Architecture/Application.h"
#include "Logging/Console.h"

extern Application* CreateApplication();

void Initialize()
{
    Console::Init();
    SDL_INIT sdl_init;

    Console::GetEngineLogger().info("Engine initialized successfully.");
}

int main(int argc, char** argv)
{
    Initialize();

    Application* app = CreateApplication();
    app->Run();
    delete app;
}
