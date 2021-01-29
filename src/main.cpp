#include <SDL.h>
#include <stdio.h>
#include "main_window.h"
#include "random_gen.h"

int main( int argc, char* argv[] )
{
	ran::args the_args = ran::parse(argc, argv);
	if(the_args.num_clusters == -1) return 1;
	

if (mainw::initialize(&the_args)) return 1;

	mainw::loop();

	mainw::quit();

	return 0;
}
