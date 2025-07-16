#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <eng/screen.h>
#include <eng/vector.h>
#include <eng/input.h>

eng_screen screen;

void loop() {
	system("clear");
	eng_screen_render(&screen);
}

int main() {
	screen = eng_new_screen(eng_new_ivec2(16*4, 9*4));

	eng_disable_input_buffering();

	char input;
	while (true) {
		loop();	
		
		system("sleep 0.1");

		if (read(STDIN_FILENO, &input, 1) <= 0) {
			continue;
		}
		if (input == 27) {
			break;
		}
	}

	atexit(eng_restore_input_buffering);
}
