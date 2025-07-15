#include <stdio.h>
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
    for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			int index = x + y*self->width;
			printf("%c", eng_array_get(char, self->buffer, index));
			printf("%c", eng_array_get(char, self->buffer, index));
		}
		printf("\n");
	}
}

void eng_screen_render(eng_screen* self) {
	system("clear");

	eng_ivec2 dots[6];
	dots[0] = eng_new_ivec2(0, 0);
    dots[1] = eng_new_ivec2(1, 0);
    dots[2] = eng_new_ivec2(2, 0);
    dots[3] = eng_new_ivec2(1, 1);
    dots[4] = eng_new_ivec2(1, 2);
    dots[5] = eng_new_ivec2(1, 3);

	char value = '#';
	for (int i = 0; i < 6; i++) {
        int index = dots[i].x + dots[i].y*self->width;
        eng_array_set(self->buffer, index, value);
    }

    render_buffer(self);	
}
