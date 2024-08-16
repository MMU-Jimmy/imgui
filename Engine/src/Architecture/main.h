#pragma once
using namespace IonixEngine;

#define SDL_MAIN_HANDLED
#include "SDL/SDL_INIT.h"

#include "Architecture/Application.h"
#include "Logging/Console.h"

namespace ClientApp
{
    extern IonixEngine::Application* CreateApplication();
}

void Initialize()
{
    Console::Init();
    SDL_INIT sdl_init;

    Console::GetEngineLogger().info("Engine initialized successfully.");
}

int main(int argc, char** argv)
{
    Initialize();

    auto app = ClientApp::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
