#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>

SDL_Window* init()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		return NULL;
	}
	else
	{
		SDL_Window* window = SDL_CreateWindow("sdlTube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN);
		
		if(window == NULL)
		{
			return NULL;
		}
		else
		{
			if(TTF_Init() == -1)
			{
				return NULL;
			}
			else
			{
				SDL_ShowCursor(SDL_DISABLE);
				return window;
			}
		}
	}
}