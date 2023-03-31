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
	
	keypad(stdscr, TRUE);

	printw("F1 to exit");
	refresh();

	WINDOW *content_window = create_content_window();

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {

		}
	}

	endwin();
	return 0;
}
