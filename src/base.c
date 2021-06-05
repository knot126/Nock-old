/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Base Game Utilities
 */

#include <stdio.h>

#if !defined(GLEW_INCLUDED_OK)
	#include "glad.h"
	#define GLEW_INCLUDED_OK 1
#endif
#include <GLFW/glfw3.h>

#include "base.h"

int base_init(Game *game, int width, int height, const char *title) {
	if (!glfwInit()) {
		return -1;
	}
	
	game->window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	if (!game->window) {
		printf("ERROR: Failed to create new window !\n");
		
		return -1;
	}
	
	glfwMakeContextCurrent(game->window);
	
	if (!gladLoadGLLoader((GLADloadproc) &glfwGetProcAddress)) {
		printf("ERROR: Failed to load GL function pointers !\n");
		
		return -1;
	}
	
	return 0;
}

int base_update(Game *game) {
	glClearColor((game->scene.background.r / 255.0f), (game->scene.background.g / 255.0f), (game->scene.background.b / 255.0f), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(game->window);
	glfwPollEvents();
	
	if (glfwGetKey(game->window, GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(game->window, true);
	}
	
	return glfwWindowShouldClose(game->window);
}

void base_free(Game *game) {
	glfwTerminate();
}

void scene_set_colour(Scene *scn, Colour bg, Colour fg, Colour p) {
	scn->foreground = fg;
	scn->background = bg;
	scn->player = p;
}
