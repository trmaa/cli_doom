#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_DEFAULT_CAPACITY 17

typedef struct {
    void* (*alloc)(size_t size);
    void* (*realloc)(void* ptr, size_t new_size);
    void (*free)(void* ptr);
} eng_allocator_t;

extern eng_allocator_t eng_alct;

typedef struct {
    size_t size;
    size_t capacity;
    eng_allocator_t* alct;
} eng_array_header;

#define eng_array_header(a) ((eng_array_header*)(a) - 1)

void* eng_new_array(size_t item_size, size_t capacity, eng_allocator_t* alct);
void* eng_array_push_impl(void* array, void* value, size_t item_size);
void* eng_array_set_impl(void* array, int index, void* value, size_t item_size);
void* eng_array_get_impl(void* array, int index, size_t item_size);
void  eng_array_free_impl(void* array);

#define eng_array(T, a) (T*)eng_new_array(sizeof(T), ARRAY_DEFAULT_CAPACITY, a)
#define eng_array_push(arr, val) \
    do { typeof(val) tmp = (val); arr = eng_array_push_impl(arr, &tmp, sizeof(tmp)); } while (0)
#define eng_array_set(arr, index, val) \
    do { typeof(val) tmp = (val); eng_array_set_impl(arr, index, &tmp, sizeof(tmp)); } while (0)
#define eng_array_get(T, arr, index) \
    (*(T*)eng_array_get_impl(arr, index, sizeof(T)))
#define eng_array_free(arr) \
    do { eng_array_free_impl(arr); arr = NULL; } while (0)

#endif
