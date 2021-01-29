#include <SDL.h>
#include <stdio.h>
#include "main_window.h"
#include "random_gen.h"

int main( int argc, char* args[] )
{
	//ran::args the_args = ran::parse(argc, args)
	ran::args the_args;
	
	if (mainw::initialize(&the_args)) return 1;

	mainw::loop();

	mainw::quit();

	return 0;
}
