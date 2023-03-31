#include <ncurses.h>
#include <stdbool.h>

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border);
WINDOW *create_content_window();
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

WINDOW *create_content_window() {
	WINDOW *information, *information_content;
	int startx, starty, width, height;

	startx = 0;
	starty = 0;
	width = 20;
	height = 15;

	information = create_newwin(height, width, starty, startx, true);
	information_content = create_newwin(height - 2, width -2, starty + 1, startx + 1, false);
	wprintw(information_content, "Unsigned:\n8-bit:\n16-bit:\n32-bit:\n\nSigned:\n8-bit:\n16-bit:\n32-bit:\n64-bit:\n\nOffset:\nBin:");

	wrefresh(information_content);
	
	return information_content;
}

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	if (border) { box(local_win, 0, 0); }

	wrefresh(local_win);

	return local_win;
}
