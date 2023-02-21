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
    #include <string.h>

    typedef struct file_data {
        char* program_path;
        char** active_file_arbo;
    } file_data_t;

    typedef struct global {
        file_data_t file_data;
    } global_t;

    #define program_path global->file_data.program_path

    void main_menu(global_t *global);
    void print_help(void);
    void setup_options(global_t *global, int i);
    void github_menu(global_t *global);
    void github_options(global_t *global, int i);
    void intra_menu(global_t *global);
    void intra_options(global_t *global, int i);
    void gen_menu(global_t *global);
    void gen_options(global_t *global, int i);
    void check_menu(global_t *global);
    void check_options(global_t *global, int i);
#endif
