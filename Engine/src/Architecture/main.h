#pragma once
#define SDL_MAIN_HANDLED
#include "SDL/SDL_INIT.h"

#include "Architecture/Application.h"

extern Application* CreateApplication();

void Initialize()
{
    SDL_INIT* sdl_init = new SDL_INIT();
}

int main(int argc, char** argv)
{
    Initialize();

    Application* app = CreateApplication();
    app->Run();
    delete app;

    return 0;
}