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
#include "array.hpp"

int Graphics::init(int width, int height, const char *title) {
	/**
	 * Initialise graphics subsystem
	 */
	
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
	
	this->vertex.init();
	this->index.init();
	
	glGenBuffers(1, &this->vbo);
	glGenBuffers(1, &this->ebo);
	this->loadProgramme("shader.glsl");
	
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	
	return 0;
}

void Graphics::update(void) {
	/**
	 * Update graphics subsystem
	 */
	
	glClearColor((this->background.r / 255.0f), (this->background.g / 255.0f), (this->background.b / 255.0f), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(this->window);
	glfwPollEvents();
	
	if (this->index.count && this->vertex.count) {
		glBufferData(GL_ARRAY_BUFFER, this->vertex.count * sizeof(Vertex), this->vertex.data, GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->index.count * sizeof(int), this->index.data, GL_DYNAMIC_DRAW);
		
		glDrawElements(GL_TRIANGLES, this->index.count, GL_UNSIGNED_INT, NULL);
	}
}

void Graphics::free(void) {
	/**
	 * Free graphics subsystem
	 */
	
	glfwTerminate();
}

/**
 * Other Functions
 */

int Graphics::loadProgramme(const char * const path) {
	/**
	 * Load a programme. Note that there is only one programme.
	 */
	
	int vert, frag;
	
	FILE *f = fopen(path, "rb");
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	rewind(f);
	
	char *src = (char *) malloc(len + 1);
	
	if (!src) {
		return 1;
	}
	
	vert = fread(src, 1, len, f);
	src[len] = '\0';
	
	fclose(f);
	
	if (vert != len) {
		::free(src);
		return 1;
	}
	
	// Actually start to load the shader...
	
	vert = glCreateShader(GL_VERTEX_SHADER);
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	
	const char *source[2] = {"#define VERTEX", src};
	glShaderSource(vert, 2, source, NULL);
	
	source[1] = "#define FRAGMENT";
	glShaderSource(frag, 2, source, NULL);
	
	::free(src);
	
	glCompileShader(vert);
	glCompileShader(frag);
	
	// Check for compile errors
	
	int stat;
	char msg[1024];
	
	glGetShaderiv(vert, GL_COMPILE_STATUS, &stat);
	if (!stat) {
		glGetShaderInfoLog(vert, 1024, NULL, msg);
		printf("== Shader compile failure ==\n%s\n", msg);
		return stat;
	}
	
	glGetShaderiv(frag, GL_COMPILE_STATUS, &stat);
	if (!stat) {
		glGetShaderInfoLog(frag, 1024, NULL, msg);
		printf("== Shader compile failure ==\n%s\n", msg);
		return stat;
	}
	
	// Create the programme
	
	this->prgm = glCreateProgram();
	glAttachShader(this->prgm, vert);
	glAttachShader(this->prgm, frag);
	glLinkProgram(this->prgm);
	
	// Check for errors
	glGetProgramiv(this->prgm, GL_LINK_STATUS, &stat);
	if (!stat) {
		glGetProgramInfoLog(frag, 1024, NULL, msg);
		printf("== Program link failure ==\n%s\n", msg);
		return stat;
	}
	
	glDeleteShader(vert);
	glDeleteShader(frag);
	
	glUseProgram(this->prgm);
	
	return 0;
}

void Graphics::freeProgramme(void) {
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
	glDeleteVertexArrays(1, &this->vao);
	glDeleteProgram(this->prgm);
}
