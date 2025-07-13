#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"

void loop() {
	system("clear");
	char* screen = malloc(192*108);
	screen = get_screen();
	for (int i = 0; i < 192*108; i++) {
		printf("%c", screen[i]);
		if (i % 192) {
			printf("\n");
		}
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
