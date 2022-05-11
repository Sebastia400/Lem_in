/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    typedef struct s_info_slots {
        int pos_x;
        int pos_y;
        bool busy;
        int distance;
        char *name;
        int num_checked;
        bool used_path;
        struct s_info_slots *next;
        struct s_info_slots *prev;
        int *forks_cheked;
        struct s_info_slots **forks;
    } t_info_slots;

    typedef struct s_info_path {
        int num_steps;
        int num_ants;
        char *name;
        int busy;
        bool valid;
        struct s_info_path *prev;
        struct s_info_path *next;
    } t_info_path;

    typedef struct t_var {
        int exit_status;
        char **map;
        char **inf;
        int num_ants;
        int ants_moved;
        char *start;
        char *end;
        char *path;
        int steps;
        int invalid_sentence;
        int final_steps;
        char *travel;
        struct s_info_path **pointer_paths;
        struct s_info_slots *pointer_slots;
    } s_var;
#endif
