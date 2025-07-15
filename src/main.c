#include <stdio.h>
#include <stdbool.h>
#include "array.h"

void loop() {}

int main() {
	int* arr = eng_array(int, &eng_alloc);
	for (int i = 0; i < ENG_ARRAY_DEFAULT_CAPACITY; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < ENG_ARRAY_DEFAULT_CAPACITY; i++) {
		printf("%d\n", arr[i]);
	}
}
