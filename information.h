#ifndef INFORMATION_H
#define INFORMATION_H
#include <ncurses.h>
#include <stdbool.h>

WINDOW *create_content_window();
WINDOW *create_newwin(int height, int width, int starty, int startx, bool border);
void update_content_window(WINDOW* local_win, long int data, int offset);

#endif
