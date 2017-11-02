#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<string>
#include<stdio.h>

bool window(SDL_Window* vidWindow)
{
	bool quit = false;
	
	SDL_Event e;
	SDL_Renderer* rend = NULL;
	
	//TODO: This all needs to be moved to init.cpp
	rend = SDL_CreateRenderer(vidWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	SDL_Joystick* controler = NULL;
	controler = SDL_JoystickOpen(0);
	if(controler)
	{
		SDL_JoystickEventState(SDL_ENABLE);
	}
	else
	{
		printf("Joystick failed to intialize: %s\n", SDL_GetError());
	}
	TTF_Font* sans = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 50);
	SDL_Color white = {255, 255, 255};
	
	if(!sans)
	{
		printf("TTF failed to create font: %s\n", TTF_GetError());
		quit = true;
	}
	
	while(!quit)
	{
		Uint8 buttonID;
		SDL_Surface* surface = NULL;
		SDL_Texture* message = NULL;
		
		while(SDL_PollEvent(&e) != 0)
		{
			switch(e.type)
			{
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							quit = true;
							
						default:
							buttonID = e.key.keysym.sym;
						break;
					}
				break;
					
				case SDL_JOYBUTTONDOWN:
					buttonID = e.jbutton.button;
				break;
					
				case SDL_QUIT:
					quit = true;
				break;
			}			
		}
		
		SDL_RenderClear(rend);
		
		if(buttonID)
		{
			surface = TTF_RenderText_Solid(sans, reinterpret_cast<const char*>(&buttonID), white);
		
			if(surface == NULL)
			{
				printf("SDL failed to create surface: %s\n", SDL_GetError());
				quit = true;
			}

			message = SDL_CreateTextureFromSurface(rend, surface);
			if(message == NULL)
			{
				printf("SDL failed to create texture: %s\n", SDL_GetError());
				quit = true;
			}

			SDL_Rect txtbox;
			txtbox.x = 0;
			txtbox.y = 0;
			txtbox.w = 100;
			txtbox.h = 100;

			SDL_RenderCopy(rend, message, NULL, &txtbox);
		}
		else
		{
			surface = TTF_RenderText_Solid(sans, "No Controler Input", white);
		}
		
		SDL_RenderPresent(rend);
	}
	
	//TODO: Destroy
}