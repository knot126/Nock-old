/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Main Game Functions
 */

#include <stdbool.h>

#include "game.hpp"

int main(int argc, char *argv[]) {
	Game game;
	
	int status = game.init();
	
	if (status) {
		return status;
	}
	
	Colour a = {95, 135, 135, 255};
	Colour b = {127, 127, 127, 255};
	Colour c = {127, 127, 127, 255};
	game.scene.set_colour(a, b, c);
	
	// Main game loop
	int should_close = 0;
	
	while (!should_close) {
		should_close = game.update();
	}
	
	game.free();
	
	return 0;
}
