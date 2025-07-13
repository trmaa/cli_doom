#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"

void loop() {
	system("clear");
	//char* screen = malloc(192*108 * sizeof(char));
	//screen = get_screen();
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 16; x++) {
			printf(".");
		}
		printf("\n");
	}
}

int main() {
	initscr();
	loop();
	while (0) {
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
