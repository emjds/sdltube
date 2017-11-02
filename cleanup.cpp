#include<SDL2/SDL.h>

void clean(SDL_Window* window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}