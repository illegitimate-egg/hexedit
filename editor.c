#include "information.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int cursor_position = 0;
unsigned int old_cursor_position = 0;
size_t fsize = 0;
unsigned int block = 0;

WINDOW *content_window;

WINDOW *draw_main_window(FILE* data, size_t length, WINDOW* content_window_init) {
	WINDOW *local_win, *local_win_content;
	unsigned int window_width = 48;
	unsigned int window_height = (int)length / (int)16 + (int)1;

	content_window = content_window_init;

	fsize = length;

	local_win = create_newwin(window_height + 2, window_width + 2, 0, 22, true);
	local_win_content = create_newwin(window_height, window_width, 1, 23, false);

	wmove(local_win, 0, 1);
	wprintw(local_win, "Viewer:");
	wrefresh(local_win);

	for (int i = 0; i < length; i++) {
		fread(&block, 1, 1, data);
		wprintw(local_win_content, "%02X ", block);
	}

	wmove(local_win_content, 0, 0);
	wchgat(local_win_content, 2, A_REVERSE, 0, NULL);
	wrefresh(local_win_content);

	rewind(data);
	fread(&block, 4, 1, data);
	update_content_window(content_window, block, 00);
	return local_win_content;
}

void move_window_cursor(FILE* file, WINDOW* local_win, int direction) {
	switch(direction) {
		case 1: // Left
			if(cursor_position > 0) {
				cursor_position--;
			}
			break;	
		case 2: // Right
			if(cursor_position != fsize - 1) {
				cursor_position++;
			}
			break;
		case 3: // Down
			if(!(cursor_position + 16 > fsize - 1)) {
				cursor_position +=16;
			}
			break;
		case 4: // Up
			if(!(cursor_position - 16 > cursor_position)) {
				cursor_position -=16;
			}
			break;
	}

	wmove(local_win, 0, old_cursor_position * 3);
	wchgat(local_win, 2, A_NORMAL, 0, NULL);
	wmove(local_win, (int)cursor_position / (int)16, (cursor_position % 16) * 3);
	wchgat(local_win, 2, A_REVERSE, 0, NULL);

	fseek(file, cursor_position, SEEK_SET);
	fread(&block, 4, 1, file);
	update_content_window(content_window, block, cursor_position);

	old_cursor_position = cursor_position;
	wrefresh(local_win);
}
