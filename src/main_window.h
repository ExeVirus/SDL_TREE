#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SDL.h>
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


void tick();

void up(bool pressed);
void down(bool pressed);
void left(bool pressed);
void right(bool pressed);

} //End mainw namespace

#endif
