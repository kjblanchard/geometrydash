#include <iostream>
#include "SDL.h"
#include "initialize_audio.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool init();

int main()
{
	if (SDL_INIT_AUDIO)
		std::cout << "Initialized audio!    ";
	else
		std::cout << "Borked";

	std::cout << "Hello world!" << std::endl;
	auto windowResult = init();
	auto fmod = destroy();
	auto running = true;
	Uint32 timeMS = 0;
	Uint32 oldTimeMS = 0;
	Uint32 frameTimeMS = 0;
	Uint32 frameTime = 0;
	short num = 0;
	short FPS = 60;
	while (running)
	{
		oldTimeMS = timeMS;
		timeMS = SDL_GetTicks();
		frameTimeMS = timeMS - oldTimeMS;
		frameTime = ((float)timeMS / 1000.0f) * FPS;
		SDL_Delay(10);
		if (frameTime > 1000)
		{
			num++;
			if (num > FPS)
			{
				num = 0;
				std::cout << "60 ticks just happened\n";
			}
			fmod->update();
		}
	}
}
//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

//Current displayed image
SDL_Surface *gCurrentSurface = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}
