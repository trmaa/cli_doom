#include "screen.h"

auto get_screen() {
	char screen[SCREEN_WIDTH*SCREEN_HEIGHT];
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		screen[i] = '.';
	}
	return screen;
}
