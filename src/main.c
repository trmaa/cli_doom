#include <stdio.h>
#include <array.h>

int main() {
    int* arr = eng_array(int, &eng_alloc);

    eng_array_push(arr, 10);
    eng_array_push(arr, 20);
    eng_array_push(arr, 30);

    printf("Value at 1: %d\n", eng_array_get(int, arr, 1)); // prints 20

    eng_array_set(arr, 1, 99);
    printf("New value at 1: %d\n", eng_array_get(int, arr, 1)); // prints 99

    eng_array_free(arr);
}
