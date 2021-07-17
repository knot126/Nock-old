/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Base Game Utilities
 */

#include <stdio.h>

#include "array.hpp"
#include "game.hpp"

int Game::init(void) {
	int result;
	
	result = this->graphics.init(600, 600, "Nock");
	
	if (result != 0) {
		return result;
	}
	
	Object test;
	
	this->scene.objects.append(test);
	this->scene.objects.remove(0);
	
	return 0;
}

int Game::update(void) {
	this->graphics.update();
	
	if (glfwGetKey(this->graphics.window, GLFW_KEY_ESCAPE)) {
		glfwSetWindowShouldClose(this->graphics.window, true);
	}
	
	return glfwWindowShouldClose(this->graphics.window);
}

void Game::free(void) {
	this->graphics.free();
}

void Scene::set_colour(Colour bg, Colour fg, Colour p) {
	this->foreground = fg;
	this->background = bg;
	this->player = p;
}
