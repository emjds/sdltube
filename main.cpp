#include<SDL2/SDL.h>
#include<stdio.h>

#include "init.h"
#include "window.h"
#include "cleanup.h"

int main(int argc, char* args[])
{
	SDL_Window* pwinMain;
	bool bolWind;
	
	pwinMain = init();
	
	if(pwinMain != NULL)
	{
		bolWind = window(pwinMain);
	}
	else
	{
		printf("SDL failed to initialize: %s\n", SDL_GetError());
	}
	
	clean(pwinMain);
	
	printf("SDL DEBUG: %s\n", SDL_GetError());
	
	return 0;
}