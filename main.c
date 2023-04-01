#include <ncurses.h>
#include <stdbool.h>
#include "information.h"

void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]) {
	int ch;

	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	
	keypad(stdscr, TRUE);

	printw("F1 to exit");
	refresh();

	WINDOW *content_window = create_content_window();
	update_content_window(content_window, -16934, 0x3A);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {

		}
	}

	endwin();
	return 0;
}
