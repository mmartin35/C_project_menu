/*
** Language        : C
** Title           : master.c
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 18/01/2023 at 12:38:26
*/
#include "../include/global.h"

const char *active_proj = ".";
const char *test_env = ".";

void print_help(void)
{
    printf("This menu serves epitech students to simplify access to common used ressources in all our projects.\n");
    printf("You must change the header and some other details in certain bash scripts to be able to use it perfectly\n");
}

int main(int argc, char** argv)
{
    if (argc == 1)
        main_menu();
    else if (strcmp(argv[1], "-h") == 0)
        print_help();
    else
        return 84;
    return 0;
}

void main_menu(void)
{
    int ch, i = 0;
    char list[7][7] = { "Work", "Github", "Gen", "Check", "Intra", "Test", "Exit" };
    char item[8];

    WINDOW *win;
    initscr();
    win = newwin(10, 12, 1, 1);
    box(win, 0, 0);

    for (i = 0; i < 7; i++) {
        if (i == 0) wattron(win, A_STANDOUT);
        else wattroff(win, A_STANDOUT);
        sprintf(item, "%-7s",  list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
    }

    wrefresh(win);
    noecho();
    keypad(win, TRUE);
    curs_set(0);

    i = 0;
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

    switch (i) {
        case 0:
            system("echo current work...");
            break;
        case 1:
            github_menu();
            break;
        case 2:
            gen_menu();
            break;
        case 3:
            check_menu();
            break;
        case 4:
            intra_menu();
            break;
        case 5:
            system("echo test env...");
            break;
        case 6:
            system("");
            break;
    }
}
