/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Base Game Utilities
 */ 

#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include <GLFW/glfw3.h>

#include "graphics.hpp"
#include "array.hpp"
#include "types.hpp"

typedef struct Object {
	Vec3 pos;
	Vec3 rot;
	Vec3 size;
} Object;

typedef struct Scene {
	Array<Object> objects;
	
	Colour foreground;
	Colour background;
	Colour player;
	
	void set_colour(Colour bg, Colour fg, Colour p);
} Scene;

typedef struct Game {
	Graphics graphics;
	Scene scene;
	
	int init(void);
	int update(void);
	void free(void);
} Game;
