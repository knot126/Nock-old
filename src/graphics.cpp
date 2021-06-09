/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Graphics
 */

#include <stdio.h>

#if !defined(GLEW_INCLUDED_OK)
	#include "glad/glad.h"
	#define GLEW_INCLUDED_OK 1
#endif
#include <GLFW/glfw3.h> 

#include "graphics.hpp"

int Graphics::init(int width, int height, const char *title) {
	if (!glfwInit()) {
		return -1;
	}
	
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	if (!this->window) {
		printf("ERROR: Failed to create new window !\n");
		
		return -1;
	}
	
	glfwMakeContextCurrent(this->window);
	
	if (!gladLoadGLLoader((GLADloadproc) &glfwGetProcAddress)) {
		printf("ERROR: Failed to load GL function pointers !\n");
		
		return -1;
	}
	
	return 0;
}

void Graphics::update(void) {
	glClearColor((this->background.r / 255.0f), (this->background.g / 255.0f), (this->background.b / 255.0f), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

void Graphics::free(void) {
	glfwTerminate();
}
