#ifndef RANDOM_GEN_H
#define RANDOM_GEN_H

namespace ran {

struct args {
	int num_clusters;
	int num_total_points;
	float spread_multiplier;	
};

//---------------------
//  ran::parse(int arc, char* argv);
//
// Only 4 paramaters are allowed, no more or less.
// Must provide num_clusters num_total_points spread_multiplier
// Otherwise, usage is printed to stdout 
args parse(int argc, char* argv[]);

void generate(args the_args);

}
#endif
