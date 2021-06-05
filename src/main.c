/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Main Game Functions
 */

#include <stdbool.h>

#include "base.h"

int main(int argc, char *argv[]) {
	Game game;
	
	int status = base_init(&game, 800, 600, "Nock");
	
	if (status) {
		return status;
	}
	
	Colour a = {.r = 95, .g = 135, .b = 135, .a = 255};
	Colour b = {.r = 127, .g = 127, .b = 127, .a = 255};
	Colour c = {.r = 127, .g = 127, .b = 127, .a = 255};
	scene_set_colour(&game.scene, a, b, c);
	
	// Main game loop
	int should_close = 0;
	
	while (!should_close) {
		should_close = base_update(&game);
	}
	
	base_free(&game);
	
	return 0;
}
