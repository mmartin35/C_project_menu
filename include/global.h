/*
** Language        : C
** Title           : global.h
** File description:
** <------------------------------------------->
** Made by         : matthieu1.martin@epitech.eu
** Creation date   : 18/01/2023 at 12:39:22
*/
#pragma once
#ifndef GLOBAL_H_
    #define GLOBAL_H_

    #include <ncurses.h>
    #include <stdlib.h>

    typedef struct file_data {
        char** active_file_arbo;
    } file_data_t;

    typedef struct global {
        file_data_t file_data;
    } global_t;

    void main_menu(global_t *global);
    void setup_options(int i);
    void github_menu(void);
    void github_options(int i);
    void intra_menu(void);
    void intra_options(int i);
#endif
