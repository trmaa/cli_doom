#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <eng/screen.h>
#include <eng/vector.h>
#include <eng/input.h>

#include <termios.h>
#include <fcntl.h>

eng_screen screen;

void loop() {
	system("clear");
	screen.render();
}

int main() {
	screen = eng_new_screen(eng_new_ivec2(64, 48));

	eng_disable_input_buffering();

	char input;
	while (true) {
		loop();	

		if (read(STDIN_FILENO, &input, 1) <= 0) {
			continue;
		}
		if (input == 27) {
			break;
		}
	}

	atexit(eng_restore_input_buffering);
}
