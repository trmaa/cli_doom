#include <stdio.h>
#include "screen.h"
#include "array.h"

eng_screen eng_new_screen(eng_ivec2 resolution) {
	eng_screen scr;
	scr.buffer = eng_array(char, &eng_alct);
	scr.render = &eng_screen_render;
	return scr;
}

void eng_screen_render() {
	printf("hello, CDOOM\n");
}
