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
    initscr();
    raw();
    page_disp(global);
    getch();
    endwin();
}

void page_disp(global_t *global)
{
    struct dirent **namelist;
    int n = scandir(".", &namelist, NULL, alphasort);
    refresh();
    printf("\n");
    while (n--) {
        printw("  %s", namelist[n]->d_name);
        free(namelist[n]);
    }
    free(namelist);
}
