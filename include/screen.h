#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_WIDTH 48 
#define SCREEN_HEIGHT 27 

typedef struct {
    char* buffer; 
	void (*render)(char** buffer);
} eng_screen;

eng_screen* new_eng_screen();

void eng_screen_render(char** buffer);

#endif
