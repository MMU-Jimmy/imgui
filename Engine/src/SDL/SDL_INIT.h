#pragma once
#include "Architecture/Macros.h"
#include <iostream>
#include "SDL.h"

static bool s_SDLInitialized = false;

class SDL_INIT
{
public:
	SDL_INIT()
	{ 
		if (!s_SDLInitialized)
		{
			int success = SDL_Init(SDL_INIT_VIDEO);

			s_SDLInitialized = success == 0 ? true : false;

			std::string sdl_init_err = "SDL Initialized: ";
			std::cout << (s_SDLInitialized ? sdl_init_err + "Success" : sdl_init_err + "Fail");

			// Initialize SDL with Glad below (ImGUI rendering)
			// ..
			// ..
		}
	}

	~SDL_INIT() { SDL_Quit(); }
};