/*
** Language        : C
** Title           : terminal_ui.c
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 23/12/2022 at 19:12:28
*/

#pragma once
#ifndef TERMINAL_UI_H
    #define TERMINAL_UI_H

// INCLUDES:
    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <string.h>
    #include <dirent.h>
// STRUCT:

    typedef struct list {
        int arrow_pos;
    } list_t;

    typedef struct global {
        list_t list;
    } global_t;

// MACROS:

    #define arrow_pos global->list.arrow_pos


// FUNCTIONS:

    void init_window(global_t *global);
    void start_page(global_t *global);
    void page_disp(global_t *global);

#endif
