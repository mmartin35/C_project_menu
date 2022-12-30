// C PROGRAM TEST

#include <ncurses.h>
#include <dirent.h>

int main()
{
    WINDOW *win;

    struct dirent **namelist;
    int n = scandir(".", &namelist, NULL, alphasort);

    char list[5][7] = { "One", "Two", "Three", "Four", "Five" };
    char item[7];
    int ch, i = 0, width = 7;
    initscr();
    win = newwin(10, 12, 1, 1); // create a new window
    box(win, 0, 0); // sets default borders for the window
// now print all the menu items and highlight the first one
    for (i = 0; i < 5; i++) {
        if (i == 0) 
            wattron(win, A_STANDOUT); // highlights the first item.
        else
            wattroff(win, A_STANDOUT);
        sprintf(item, "%-7s",  list[i]);
    mvwprintw(win, i + 1, 2, "%s", item);
    }
    wrefresh(win); // update the terminal screen
    i = 0;
    noecho();
    keypad(win, TRUE);
    curs_set(0); // hide the default screen cursor.
    while((ch = wgetch(win)) != 27){ 
// right pad with spaces to make the items appear with even width.
        sprintf(item, "%-7s", list[i]); 
        mvwprintw(win, i + 1, 2, "%s", item); 
// use a variable to increment or decrement the value based on the input.
        switch(ch) {
            case KEY_UP:
                        i--;
                        i = (i < 0) ? 4 : i;
                        break;
            case KEY_DOWN:
                        i++;
                        i = (i > 4) ? 0 : i;
                        break;
        }
// now highlight the next item in the list.
        wattron(win, A_STANDOUT);
        sprintf(item, "%-7s", list[i]);
        mvwprintw(win, i + 1, 2, "%s", item);
        wattroff(win, A_STANDOUT );
    }
    delwin(win);
    endwin();
}
