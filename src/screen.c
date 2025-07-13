#include <stdlib.h>
#include "screen.h"

eng_screen* new_eng_screen() {
    eng_screen* screen;
    screen->buffer = malloc(SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(char));
    screen->render = &eng_screen_render;
    return screen;
}

void eng_screen_render(char** buffer) {
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		*buffer[i] = '.';
	}
}
