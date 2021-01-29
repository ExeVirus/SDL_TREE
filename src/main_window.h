#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SDL.h>
#include "controls.h"
#include "random_gen.h"

namespace mainw {

//-------------------------
// mainw::initialize()
//
// Starts SDL2
//
// Returns 1 on Error
//
int initialize(ran::args* arg);


//-------------------------
// mainw::initialize()
//
// Runs main game loop
//
void loop();

//-------------------------
// mainw::quit()
// Quits SDL
//
void quit();

//-------------------------
// mainw::respond()
// Uses controls from keyboard to 
// move the player, change the current check, etc.
//
void respond(con::control_struct controls);

} //End mainw namespace

#endif
