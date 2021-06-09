/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Generic Array
 */

#pragma once

#include <stdlib.h>

template<typename BaseType>
struct Array {
	BaseType *data;
	size_t count;
	
	void init(void);
	void free(void);
	void append(BaseType object);
	void trim(size_t amount);
	void remove(size_t index);
	size_t length(void);
};
