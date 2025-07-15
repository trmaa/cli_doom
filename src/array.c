#include <array.h>

eng_allocator_t eng_alloc = {
    .alloc = malloc,
    .realloc = realloc,
    .free = free,
};

void* eng_new_array(size_t item_size, size_t capacity, eng_allocator_t* alct) {
    size_t total_size = sizeof(eng_array_header) + (item_size * capacity);
    eng_array_header* head = alct->alloc(total_size);

    if (!head) return NULL;

    head->size = 0;
    head->capacity = capacity;
    head->alct = alct;

    return head + 1;
}

void* eng_array_push_impl(void* array, void* value, size_t item_size) {
    eng_array_header* head = eng_array_header(array);
    
    if (head->size >= head->capacity) {
        size_t new_capacity = head->capacity * 2;
        size_t new_size = sizeof(eng_array_header) + item_size * new_capacity;
        eng_array_header* new_head = head->alct->realloc(head, new_size);
        if (!new_head) return array;

        new_head->capacity = new_capacity;
        head = new_head;
        array = new_head + 1;
    }

    void* dest = (char*)array + (head->size * item_size);
    memcpy(dest, value, item_size);
    head->size += 1;

    return array;
}

void* eng_array_set_impl(void* array, int index, void* value, size_t item_size) {
    eng_array_header* head = eng_array_header(array);
    if (index >= 0 && (size_t)index < head->size) {
        void* dest = (char*)array + (index * item_size);
        memcpy(dest, value, item_size);
    }
    return array;
}

void* eng_array_get_impl(void* array, int index, size_t item_size) {
    eng_array_header* head = eng_array_header(array);
    if (index >= 0 && (size_t)index < head->size) {
        return (char*)array + (index * item_size);
    }
    return NULL;
}

void eng_array_free_impl(void* array) {
    if (!array) return;
    eng_array_header* head = eng_array_header(array);
    head->alct->free(head);
}
