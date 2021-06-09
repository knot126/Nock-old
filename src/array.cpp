/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Generic Array - this won't handle errors nicely
 */ 

#include <stdlib.h>

#include "array.hpp"

template <typename BaseType>
void Array<BaseType>::init(void) {
	/**
	 * Initialise the array
	 */
	
	this->data = NULL;
	this->count = 0;
}

template <typename BaseType>
void Array<BaseType>::free(void) {
	/**
	 * Free and reset the array
	 */
	
	if (this->data) {
		free(this->data);
	}
	this->count = 0;
}

template <typename BaseType>
void Array<BaseType>::append(BaseType object) {
	/**
	 * Append a new object to the end of the array.
	 */
	
	this->count++;
	this->data = realloc(this->data, sizeof(BaseType) * this->count);
	
	if (this->data) {
		this->data[this->count - 1] = object;
	}
}

template <typename BaseType>
void Array<BaseType>::trim(size_t amount) {
	/**
	 * Trim the array by amount.
	 */
	
	this->count -= amount;
	this->data = realloc(this->data, sizeof(BaseType) * this->count);
}

template <typename BaseType>
void Array<BaseType>::remove(size_t index) {
	/**
	 * Remove an element at index.
	 */
	
	this->count -= 1;
	
	// Only move memory up if not at the end
	if (this->count - index != 0) {
		memmove(this->data + index, this->data + index + 1, (this->count - index) * sizeof(BaseType));
	}
	
	this->data = realloc(this->data, sizeof(BaseType) * this->count);
}

template <typename BaseType>
size_t Array<BaseType>::length(void) {
	/**
	 * Get the length of the array.
	 */
	
	return this->count;
}
