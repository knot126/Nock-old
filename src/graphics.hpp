/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Graphics
 */

#pragma once

#include "types.hpp"

typedef struct Graphics {
	GLFWwindow *window;
	
	Colour foreground;
	Colour background;
	Colour player;
	
	int init(int width, int height, const char *title);
	void update(void);
	void free(void);
} Graphics;
