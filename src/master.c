/*
** Language        : C
** Title           : master.c
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 18/01/2023 at 12:38:26
*/
#include "../include/global.h"

int main()
{
    global_t global = {0};
    main_menu(&global);
    return 0;
}

void main_menu(global_t *global)
{
    WINDOW *win;
    char list[7][7] = { "Work", "Github", "Gen", "Check", "Intra", "Test", "Exit" };
    char item[8];
    int ch, i = 0;
    initscr();
    win = newwin(10, 12, 1, 1);
    box(win, 0, 0);
    for (i = 0; i < 7; i++) {
        if (i == 0)
            wattron(win, A_STANDOUT);
        else
            wattroff(win, A_STANDOUT);
        sprintf(item, "%-7s",  list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
    }
    wrefresh(win);
    i = 0;
    noecho();
    keypad(win, TRUE);
    curs_set(0);
    while ((ch = wgetch(win)) != 10) {
        sprintf(item, "%-7s",  list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
        switch (ch) {
		case KEY_UP:
			i--;
			i = (i < 0) ? 6 : i;
			break;
		case KEY_DOWN:
			i++;
			i = (i > 6) ? 0 : i;
			break;
        }
        wattron(win, A_STANDOUT);
        sprintf(item, "%-7s",  list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
        wattroff(win, A_STANDOUT);
    }
    delwin(win);
    endwin();
    setup_options(global, i);
}

void setup_options(global_t *global, int i)
{
    switch (i) {
	    case 0:
		    system("echo current work...");
		    break;
	    case 1:
		    github_menu(global);
		    break;
	    case 2:
		    gen_menu(global);
		    break;
	    case 3:
		    check_menu(global);
		    break;
	    case 4:
		    intra_menu(global);
		    break;
	    case 5:
		    system("echo test env...");
		    break;
	    case 6:
		    system("");
		    break;
    }
}
