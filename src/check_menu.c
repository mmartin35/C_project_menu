/*
** Language        : C
** Title           : check_menu.c
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 18/01/2023 at 12:38:26
*/
#include "../include/global.h"

void check_menu(global_t *global) {
    WINDOW *win;
    char list[4][7] = { "Page", "Cstyle", "Man", "Back" };
    char item[8];
    int ch, i = 0;
    initscr();
    win = newwin(10, 12, 1, 1);
    box(win, 0, 0);
    for (i = 0; i < 4; i++) {
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
			i = (i < 0) ? 3 : i;
			break;
		case KEY_DOWN:
			i++;
			i = (i > 3) ? 0 : i;
			break;
        }
        wattron(win, A_STANDOUT);
        sprintf(item, "%-7s",  list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
        wattroff(win, A_STANDOUT);
    }
    delwin(win);
    endwin();
    check_options(global, i);
}

void check_options(global_t *global, int i)
{
    switch (i) {
	    case 0:
		    system("firefox --new-tab ~/GIT/personal/C_project_menu/assets/pdf/epitech_c_coding_style.pdf &");
		    break;
	    case 1:
		    system("~/GIT/personal/C_project_menu/scripts/coding_style.sh . .");
		    break;
	    case 2:
		    system("echo man...");
		    break;
	    case 3:
		    main_menu(global);
		    break;
    }
}
