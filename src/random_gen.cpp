#include <iostream>
#include <string>
#include "random_gen.h"

ran::args ran::parse(int argc, char* argv[])
{
	args local;
	local.num_clusters = -1;
	//check proper number of arguments
	if(argc ==4) {
		local.num_clusters      = std::stoi(argv[1]);
		local.num_total_points  = std::stoi(argv[2]);
		local.spread_multiplier = std::stoi(argv[3]);
	} else { 
		//show usage
		std::cout << "Improper usage entered, please enter 3 integers:"  << std::endl;
		std::cout << "num_clusters, num_total_points, spread_multiplier" << std::endl;
	}
	return local;
}
