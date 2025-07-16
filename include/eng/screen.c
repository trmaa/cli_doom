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

void render_buffer(eng_screen* this) {
	int index;
    for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {
			index = x + y*this->width;
			printf("%c", eng_array_get(char, this->buffer, index));
			printf("%c", eng_array_get(char, this->buffer, index));
		}
		printf("\n");
	}
}

const char brightness[9] = { '.', '-', '+', '*', 'x', 'o', 'X', '&', '@' };

void eng_screen_render(eng_screen* this) {
	system("clear");

	int index, bright_index, size;
	float red, green, bright;
	char value = brightness[bright_index];
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {
			index = x + y*this->width;

			red = abs(2*x - this->width) / (float)this->width;
			green = abs(2*y - this->height) / (float)this->height;
			//red = x / (float)this->width;
			//green = y / (float)this->height;

			bright = sqrtf(red*red + green*green) / sqrtf(2.f);
			//bright = (red + green) / 3;

			size = (sizeof(brightness) / sizeof(char));
			bright_index = (int)(bright*size * 0.999);

			value = brightness[bright_index];
			eng_array_set(this->buffer, index, value);
		}
	}

    render_buffer(this);	
}
