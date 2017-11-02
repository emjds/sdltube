#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<string>

bool window(SDL_Window* vidWindow)
{
	bool quit = false;
	
	SDL_Event e;
	SDL_Renderer* rend = NULL;
	
	rend = SDL_CreateRenderer(vidWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	
	SDL_Joystick* controler = NULL;
	SDL_JoystickEventState(SDL_ENABLE);
	controler = SDL_JoystickOpen(0);
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 50);
	SDL_Color white = {255, 255, 255};
	
	
	while(!quit)
	{
		Uint8 buttonID;
		
		while(SDL_PollEvent(&e) != 0)
		{
			switch(e.type)
			{
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							quit = true;
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
		
		SDL_Surface* surface = TTF_RenderText_Solid(Sans, reinterpret_cast<const char*>(&buttonID), white);
		SDL_Texture* message = SDL_CreateTextureFromSurface(rend, surface);
		
		SDL_Rect txtbox;
		txtbox.x = 0;
		txtbox.y = 0;
		txtbox.w = 100;
		txtbox.h = 100;
		
		SDL_RenderCopy(rend, message, NULL, &txtbox);
		SDL_RenderPresent(rend);
	}
}