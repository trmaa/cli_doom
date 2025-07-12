#ifndef KEYBOARD_H
#define KEYBOARD_H

#define ESC 27

#include <sys/ioctl.h>
#include <unistd.h>

int kbhit() {
	int k;
	ioctl(STDIN_FILENO, FIONREAD, &k);
	return k;
}

#endif
