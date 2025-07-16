#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "screen.h"
#include "array.h"
#include "vector.h"

eng_screen eng_new_screen(eng_ivec2 resolution) {
	eng_screen scr;
	scr.buffer = eng_array(char, &eng_alct);
	scr.width = resolution.x;
	scr.height = resolution.y;

	char val = '.';
	for (int i = 0; i < scr.width*scr.height; i++) {
		eng_array_push(&scr.buffer, val);
	}

	return scr;
}

void render_buffer(eng_screen* self) {
	int index;
    for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			index = x + y*self->width;
			printf("%c", eng_array_get(char, self->buffer, index));
			printf("%c", eng_array_get(char, self->buffer, index));
		}
		printf("\n");
	}
}

const char brightness[9] = { '.', '-', '+', '*', 'x', 'o', 'X', '&', '@' };

void eng_screen_render(eng_screen* self) {
	system("clear");

	int index, bright_index, size;
	float red, green, bright;
	char value = brightness[bright_index];
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			index = x + y*self->width;

			red = abs(2*x - self->width) / (float)self->width;
			green = abs(2*y - self->height) / (float)self->height;
			//red = x / (float)self->width;
			//green = y / (float)self->height;

			bright = sqrtf(red*red + green*green) / sqrtf(2.f);
			//bright = (red + green) / 3;

			size = (sizeof(brightness) / sizeof(char));
			bright_index = (int)(bright*size * 0.999);

			value = brightness[bright_index];
			eng_array_set(self->buffer, index, value);
		}
	}

    render_buffer(self);	
}
