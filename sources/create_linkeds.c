/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void create_prev(t_info_path *file)
{
    t_info_path *tmp = file->next;
    t_info_path *tmp2 = file;
    int i = 0;
    int j = 0;
    while (tmp != NULL) {
        tmp->prev = tmp2;
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
}

void create_path(t_info_path *file, char *name)
{
    t_info_path *tmp = file;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_linked_path(name);
}

void create_slots(t_info_slots *file, int i, int j, char *name)
{
    t_info_slots *tmp = file;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_linked_slots(i, j, name);
}
