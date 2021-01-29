#include "main_window.h"
#include "controls.h"
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
	screenSurface = NULL;()
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )()
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
	con::control_struct controls;
	while(run) 
	{
		con::do_controls(&control_struct);
		
		//If quit is pressed
		if(control_struct.quit)
			break; //out of while loop
		
		//respond to controls
		respond(&control_struct); //sets player position, toggles check
		
		if(timeHasPassed)
			tick(); //renders screen, runs the toggled check
	}
}

void mainw::quit()
{
	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
}
