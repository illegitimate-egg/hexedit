#include "information.h"
#include <stdio.h>
#include <stdlib.h>

void draw_main_window(FILE* data, size_t length) {
	WINDOW *local_win, *local_win_content;
	int window_width = 48;
	int window_height = length / 16;

	local_win = create_newwin(window_height + 2, window_width + 2, 0, 22, true);
	local_win_content = create_newwin(window_height, window_width, 1, 23, false);

	wmove(local_win, 0, 1);
	wprintw(local_win, "Viewer:");
	wrefresh(local_win);

	unsigned int block = 0;
	for (int i = 0; i < length; i++) {
		fread(&block, 1, 1, data);
		wprintw(local_win_content, "%02X ", block);
		wrefresh(local_win_content);
	}
}	
