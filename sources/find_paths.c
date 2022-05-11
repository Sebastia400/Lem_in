/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int check_result(s_var *all, t_info_path *param)
{
    t_info_path *path = param;
    t_info_slots *tmp = all->pointer_slots->next;

    int i = 0;

    while (path->next != NULL)
        path = path->next;

    while (tmp->forks[i] != NULL) {
        if (my_strcmp(path->name, tmp->forks[i]->name) == 0)
            return (0);
        i++;
    }
    return (1);
}

int find_lower_slot(t_info_slots *slots, s_var *all)
{
    int j = 0;
    int lower = slots->distance;
    int i = 0;

    while (slots->forks[j] != NULL) {
        if (slots->forks[j]->distance < lower
        && slots->forks[j]->used_path == false &&
        slots->forks[j]->distance != -1) {
            lower = slots->forks[j]->distance;
        }
        j++;
    }
    return lower;
}

int find_lower_slot_pos(t_info_slots *slots, s_var *all)
{
    int j = 0;
    int lower = slots->distance;
    int i = 0;

    while (slots->forks[j] != NULL) {
        if (slots->forks[j]->distance < lower
        && slots->forks[j]->used_path == false &&
        slots->forks[j]->distance != -1) {
            lower = slots->forks[j]->distance;
            i = j;
        }
        j++;
    }
    return i;
}

void find_paths(t_info_slots *slots, s_var *all, void *pointer_path)
{
    int i = find_lower_slot_pos(slots, all);
    int low_slot = find_lower_slot(slots, all);
    create_path(pointer_path, slots->name);
    if (my_strcmp(all->start, slots->forks[i]->name) != 0 &&
    low_slot == slots->forks[i]->distance &&
    slots->forks[i]->used_path == false) {
        slots->forks[i]->used_path = true;
        find_paths(slots->forks[i], all, pointer_path);
    }
}

void save_paths(s_var *all, t_info_slots *tmp)
{
    int i = 0;
    while (tmp->forks[i] != NULL) {
        all->pointer_paths[i] = init_linked_path(NULL);
        find_paths(tmp, all, all->pointer_paths[i]);
        if (!check_result(all, all->pointer_paths[i])) {
            all->pointer_paths[i]->valid = true;
            create_path(all->pointer_paths[i], all->start);
            create_prev(all->pointer_paths[i]);
        }
        else
            all->pointer_paths[i]->valid = false;
        i++;
    }
}
