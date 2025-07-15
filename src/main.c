#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <eng/screen.h>
#include <termios.h>
#include <fcntl.h>
#include <eng/vector.h>

void disable_input_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
}

void restore_input_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void cleanup() {
    restore_input_buffering();
    printf("\033[?25h");
}

eng_screen screen;

void loop() {
	system("clear");
	screen.render();
}

int main() {
	screen = eng_new_screen(eng_new_ivec2(64, 48));

	disable_input_buffering();
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

	atexit(cleanup);
}
