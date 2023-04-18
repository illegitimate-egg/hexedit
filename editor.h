#ifndef EDITOR_H
#define EDITOR_H
#include <ncurses.h>
WINDOW *draw_main_window(FILE* data, size_t length, WINDOW* content_window);
/*
* FUNCTION:	move_window_cursor
* --------------------------------
*
* local_win: The window to operate on
*
* direction: The direction to move the cursor in. Allows these values:
* 	- 1 - left
* 	- 2 - Right
* 	- 3 - Down
* 	- 4 - Up
*/
void move_window_cursor(FILE* file, WINDOW* local_win, int direction);
#endif
