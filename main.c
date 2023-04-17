#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include "information.h"
#include "editor.h"

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

	FILE *file;
	file = fopen("main.c","rb");
	
	fseek(file, 0L, SEEK_END);
	size_t sz = ftell(file);
	rewind(file);

	WINDOW *content_window = create_content_window();
	update_content_window(content_window, -16934, 0x3A);
	draw_main_window(file, sz);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {

		}
	}

	fclose(file);
	endwin();
	return 0;
}
