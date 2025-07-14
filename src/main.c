#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"

eng_screen main_screen;

void loop() {
	system("clear");

    main_screen.render(&main_screen.buffer);

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			int i = x + y*SCREEN_WIDTH;
			printf("%c%c", main_screen.buffer[i], main_screen.buffer[i]);
		}
		printf(".\r\n");
	}
}

int main() {
    main_screen = new_eng_screen();

	initscr();
	while (1) {
		loop();
		system("sleep $((1/60))");

		if (!kbhit()) {
			continue;
		}
		if (getch() == ESC) {
			break;
		}
	}
	endwin();

	free(main_screen.buffer);
}
