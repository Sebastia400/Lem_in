/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

s_var *init_struct(void)
{
    s_var *all = malloc(sizeof(s_var));
    all->exit_status = 0;
    all->invalid_sentence = 0;
    all->inf = NULL;
    return (all);
}

t_info_slots *init_struct_slots(void)
{
    t_info_slots *tmp = malloc(sizeof(t_info_slots) * 1);
    tmp->next = NULL;
    tmp->forks = malloc(sizeof(t_info_slots *) * 100);
    tmp->forks[0] = NULL;
    return (tmp);
}

t_info_path *init_struct_path(void)
{
    t_info_path *tmp = malloc(sizeof(t_info_path) * 1);
    tmp->next = NULL;
    tmp->name = NULL;
    tmp->prev = NULL;
    return (tmp);
}

t_info_slots *init_linked_slots(int i, int j, char *name)
{
    t_info_slots *tmp = malloc(sizeof(t_info_slots) * 1);
    tmp->pos_x = j;
    tmp->pos_y = i;
    tmp->name = name;
    tmp->num_checked = 0;
    tmp->distance = -1;
    tmp->forks_cheked = malloc(sizeof(int) * 100);
    tmp->forks_cheked = my_memset(tmp->forks_cheked, 0, 100);
    tmp->forks = malloc(sizeof(t_info_slots *) * 100);
    tmp->forks[0] = NULL;
    tmp->used_path = false;
    tmp->busy = false;
    tmp->next = NULL;
    return (tmp);
}

t_info_path *init_linked_path(char *name)
{
    t_info_path *tmp = malloc(sizeof(t_info_path) * 1);
    tmp->name = (name);
    tmp->busy = false;
    tmp->num_steps = 0;
    tmp->next = NULL;
    tmp->prev = NULL;
    return (tmp);
}