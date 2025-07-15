#include <stdlib.h>
#include "array.h"

eng_allocator_t eng_alloc = {
	.alloc = malloc,
	.realloc = realloc,
	.free = free
};

void* eng_new_array(size_t item_size, size_t capacity, eng_allocator_t* alct) {
	void* ptr = 0;
	size_t size = item_size * capacity * sizeof(eng_array_header);
	eng_array_header* head = alct->alloc(size);

	if (head) {
		head->capacity = capacity;
		head->size = 0;
		head->alct = alct;
		ptr = head + 1;
	}

	return ptr;
}
