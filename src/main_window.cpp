#include "main_window.h"
#include <SDL.h>
#include <iostream>

//globals for main_window
SDL_Window* window;
SDL_Surface* screenSurface;
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool run = true;
int mainw::initialize(ran::args* arg)
{
    window = NULL;
	screenSurface = NULL;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return 1;
	}
	
	//Create window
	window = SDL_CreateWindow( "SDL Tree", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( window == NULL )
	{
		printf( "Error during window creation, SDL_Error: %s\n", SDL_GetError() );
		return 1;
	}
	return 0;
}

void mainw::loop()
{
	bool quit = false;
	SDL_Event event;
	while(!quit) 
	{ //Event Loop
		while( SDL_PollEvent( &event ) )
        {
			if( event.type == SDL_QUIT )
                quit = true;
            if( event.type == SDL_KEYDOWN ) {
				switch( event.key.keysym.sym )
                {
                    case SDLK_UP:    up(true);    break;
                    case SDLK_DOWN:  down(true);  break;
                    case SDLK_LEFT:  left(true);  break;
                    case SDLK_RIGHT: right(true); break;
                }
			}
			if( event.type == SDL_KEYUP ) {
				switch( event.key.keysym.sym )
                {
                    case SDLK_UP:    up(false);    break;
                    case SDLK_DOWN:  down(false);  break;
                    case SDLK_LEFT:  left(false);  break;
                    case SDLK_RIGHT: right(false); break;
                }
			}
		}
	}
}

void mainw::quit()
{
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
}

void mainw::tick(){}

void mainw::up(bool pressed)
{
	if(pressed)
		std::cout << "UP."    << std::endl;
	else
		std::cout << "UP^"    << std::endl;
}
	
void mainw::down(bool pressed)
{
	if(pressed)
		std::cout << "DOWN."    << std::endl;
	else
		std::cout << "DOWN^"    << std::endl;
}
	
void mainw::left(bool pressed)
{
	if(pressed)
		std::cout << "LEFT."    << std::endl;
	else
		std::cout << "LEFT^"    << std::endl;
}
	
void mainw::right(bool pressed)
{
	if(pressed)
		std::cout << "RIGHT."    << std::endl;
	else
		std::cout << "RIGHT^"    << std::endl;
}
