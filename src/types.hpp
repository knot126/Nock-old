/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Common types
 */ 

#pragma once

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
