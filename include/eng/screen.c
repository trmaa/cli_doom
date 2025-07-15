#include <stdio.h>
#include "screen.h"
#include "array.h"

eng_screen eng_new_screen(eng_ivec2 resolution) {
	eng_screen scr;
	scr.buffer = eng_array(char, &eng_alct);
	scr.width = resolution.x;
	scr.height = resolution.y;
	scr.render = &eng_screen_render;

	for (int i = 0; i < scr.width*scr.height; i++) {
		eng_array_push(&scr.buffer, '0');
	}

	return scr;
}

void eng_screen_render(eng_screen* self) {
	system("clear");

	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			int index = x + y*self->width;
			printf("%c", eng_array_get(char, self->buffer, index));
		}
		printf("\n");
	}
}
