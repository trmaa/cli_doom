#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"

void loop() {
	system("clear");
	char screen[SCREEN_WIDTH*SCREEN_HEIGHT] = get_screen();
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			int i = x + y*SCREEN_WIDTH;
			printf("%c%c", screen[i], screen[i]);
		}
		printf(".\r\n");
	}
}

int main() {
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
}
