#include <stdlib.h>
#include "screen.h"

eng_screen new_eng_screen() {
    eng_screen screen;
    screen.buffer[SCREEN_WIDTH*SCREEN_HEIGHT];
    screen.render = &eng_screen_render;
    return screen;
}

void eng_screen_render(char* buffer[SCREEN_WIDTH*SCREEN_HEIGHT]) {
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		buffer[i] = '.';
	}
}
