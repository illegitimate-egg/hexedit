#include <ncurses.h>
#include <stdbool.h>

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	if (border) { box(local_win, 0, 0); }

	wrefresh(local_win);

	return local_win;
}

WINDOW *create_content_window() {
	WINDOW *information, *information_content;
	int startx, starty, width, height;

	startx = 0;
	starty = 0;
	width = 21;
	height = 14;

	information = create_newwin(height, width, starty, startx, true);
	wmove(information, 0, 1);
	wprintw(information, "Content:");
	wmove(information, 13, 1);
	wprintw(information, "F1 to exit");
	wrefresh(information);

	information_content = create_newwin(height - 2, width -2, starty + 1, startx + 1, false);
	wprintw(information_content, "Unsigned:\n8-bit:\n16-bit:\n32-bit:\n\nSigned:\n8-bit:\n16-bit:\n32-bit:\n\nOffset:\nBin:");

	wrefresh(information_content);
	
	return information_content;
}

void update_content_window(WINDOW* local_win, long int data, int offset) {

	wmove(local_win, 1, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 2, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 3, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 6, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 7, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 8, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 10, 8);
	wprintw(local_win, "          ");
	wmove(local_win, 11, 8);
	wprintw(local_win, "          ");

	wmove(local_win, 1, 8);
	wprintw(local_win, "%u", (unsigned int)(data & 255));
	wmove(local_win, 2, 8);
	wprintw(local_win, "%u", (unsigned int)(data & 65535));
	wmove(local_win, 3, 8);
	wprintw(local_win, "%u", (unsigned int)(data & 4294967295));

	wmove(local_win, 6, 8);
	wprintw(local_win, "%d", (signed int)(data & 255));
	wmove(local_win, 7, 8);
	wprintw(local_win, "%d", (signed int)(data & 65535));
	wmove(local_win, 8, 8);
	wprintw(local_win, "%d", (signed int)(data & 4294967295));
	
	wmove(local_win, 10, 8);
	wprintw(local_win, "0x%X", offset);

	wmove(local_win, 11, 8);
	for (int i = 7; i != 0; i--) {
		wprintw(local_win, "%d", (unsigned int)((data & (1<<i)) >> i));
	}

	wrefresh(local_win);
}
