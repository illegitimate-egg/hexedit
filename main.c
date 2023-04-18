#define VERSION "0.0.2\n"

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "information.h"
#include "editor.h"

void help() {
	printf("Usage:\nhexedit [OPTION]... [FILE]...\n\nOptions:\n-h, --help  Reveal this help message\n-v, --version  Print the version number.\n");
}

void destroy_win(WINDOW *local_win);

extern int errno;

int main(int argc, char *argv[]) {
	if(argc > 1) {
		if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
			help();
			exit(0);
		} else if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
			printf(VERSION);
			exit(0);
		} else {
			help();
			exit(1);
		}
	} else {
		help();
		exit(1);
	}

	int ch;

	initscr();
	cbreak();
	raw();
	noecho();
	curs_set(0);
	
	keypad(stdscr, TRUE);

	start_color();
	use_default_colors();

	printw("F1 to exit");
	refresh();

	FILE *file;
	file = fopen(argv[1],"rb");

	if (file == NULL) {
		perror("Error opening file");
		endwin();
		exit(1);
	}
	
	fseek(file, 0L, SEEK_END);
	size_t sz = ftell(file);
	rewind(file);

	WINDOW *content_window = create_content_window();
	draw_main_window(file, sz, content_window);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {

		}
	}

	fclose(file);
	endwin();
	return 0;
}
