/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void move_ants_in_path(t_info_path *path, s_var *all, int i)
{
    while (path != NULL) {
        if (my_strcmp(path->name, all->start) == 0) {
            path->num_steps = all->final_steps;
            all->final_steps++;
            all->num_ants--;
        }
        if (path->busy == TRUE && path->prev->name != NULL ||
        my_strcmp(path->name, all->start) == 0 && all->num_ants >= 0) {
            path->busy = FALSE;
            path->prev->num_steps = path->num_steps;
            path->prev->busy = TRUE;
            my_putstr("P");
            my_put_nbr(path->num_steps);
            my_putstr("-");
            my_putstr(path->prev->name);
            my_putstr(" ");
        }
        path = path->next;
    }
}

int move_finished(s_var *all, int x)
{
    int i = 0;
    while (all->pointer_paths[i] != NULL) {
        t_info_path *path = all->pointer_paths[i];
        while (path != NULL) {
            if (path->busy == TRUE && my_strcmp(path->name, all->end) != 0
            || x == 0 || all->num_ants > 0) {
                return 0;
            }
            path = path->next;
        }
        i++;
    }
    return 1;
}

void func_move_ants(s_var *all, t_info_slots *tmp)
{
    int steps = 0;
    int i = 0;
    int j = 0;


    while (!move_finished(all, i) && all->pointer_paths[0] != NULL
    && all->pointer_paths[0]->valid != false) {
        j = 0;
        while (tmp->forks[j] != NULL) {
            if (all->pointer_paths[j] != NULL) {
                t_info_path *path = all->pointer_paths[j]->next;
                move_ants_in_path(path, all, steps);
            }
            j++;
        }
        my_putstr("\n");
        i++;
    }
}