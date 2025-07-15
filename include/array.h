#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>

#define ENG_ARRAY_DEFAULT_CAPACITY 17

#define eng_array(T, a) (T *)eng_new_array(sizeof(T), ENG_ARRAY_DEFAULT_CAPACITY, a)

typedef struct {
	void* (*alloc)(size_t size);
	void* (*realloc)(void* ptr, size_t new_size);
	void (*free)(void* ptr);
} eng_allocator_t;

extern eng_allocator_t eng_alloc;

typedef struct {
	size_t size;
	size_t capacity;
	eng_allocator_t* alct;
} eng_array_header;

void* eng_new_array(size_t item_size, size_t capacity, eng_allocator_t* alct);

#endif
