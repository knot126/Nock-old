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

typedef struct Colour {
	union {
		struct {
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint8_t a;
		};
		uint32_t as_uint32;
	};
} Colour;

typedef struct Vec3 {
	float x;
	float y;
	float z;
} Vec3;

typedef struct Object {
	Vec3 pos;
	Vec3 rot;
	Vec3 size;
} Object;

typedef struct Scene {
	Colour foreground;
	Colour background;
	Colour player;
	
	Object objects[100];
} Scene;

typedef struct Game {
	GLFWwindow *window;
	Scene scene;
} Game;

int base_init(Game *game, int width, int height, const char *title);
int base_update(Game *game);
void base_free(Game *game);

void scene_set_colour(Scene *scn, Colour bg, Colour fg, Colour p);
