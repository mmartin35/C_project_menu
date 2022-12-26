/*
** Language        : C
** Title           : master.c
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 23/12/2022 at 19:11:36
*/

#include "../include/terminal_ui.h"

int main(int argc, char **argv)
{
    global_t global = {0};
    init_window(&global);
    return 0;
}

void init_window(global_t *global)
{
    int ch;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_page(global);
    while ((ch = getch()) != 27) {
        switch (ch) {
            case KEY_LEFT:
                    arrow_pos--;
                    break;
            case KEY_RIGHT:
                    arrow_pos++;
                    break;
        }
        page_disp(global);
    }
    endwin();
}

void start_page(global_t *global)
{
    refresh();
    clear();
    printw("Welcome to this terminal file tool...\n Press any key to open. (esc to end));");
}

void page_disp(global_t *global)
{
    refresh();
    clear();
    struct dirent **namelist;
    int n = scandir(".", &namelist, NULL, alphasort);
    int len = 0;
    int count = 0;
    printw("\n");
    while ((n--) - 2) {
        printw("  %s  ", namelist[n]->d_name);
        free(namelist[n]);
    }
    printw("\n  ");
    for (int i = 2; i != 8; i++) {
        for (int j = 0; j <= (strlen(namelist[i]->d_name) - 1); j++)
            count++;
        if (arrow_pos == 0) {
            for (int k = 0; k != count; k++)
                printw(" ");
        }
        if (arrow_pos > 0) {
            for (int k = 0; k != (count / 2); k++)
                printw(" ");
            printw("0");
            for (int l = 0; l != (count / 2); l++)
                printw(" ");
        }
        printw("    ");
        count = 0;
    }
    printw("O");
    free(namelist);
}
