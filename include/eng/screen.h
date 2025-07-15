#ifndef SCREEN_H
#define SCREEN_H

#include "vector.h"

typedef struct {
	char* buffer;
	int width;
	int height;
	void (*render)();
} eng_screen;

eng_screen eng_new_screen(eng_ivec2 resolution);

void eng_screen_render();

#endif
