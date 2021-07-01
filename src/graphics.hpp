/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Graphics
 */

#pragma once

#include "types.hpp"
#include "array.hpp"

typedef struct Vertex {
	float x, y;
	float u, v;
	float r, g, b, a;
} Vertex;

typedef struct Graphics {
	GLFWwindow *window;
	
	Colour foreground;
	Colour background;
	Colour player;
	
	Array<Vertex> vertex;
	Array<int> index;
	
	unsigned int prgm, vao, vbo, ebo;
	
	int init(int width, int height, const char *title);
	void update(void);
	void free(void);
	
	int loadProgramme(const char * const name);
	void freeProgramme(void);
} Graphics;
