#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"

void loop() {
	system("clear");
	printf("%s\n", get_screen());
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
