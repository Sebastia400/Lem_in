/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void connect_between(s_var *all, t_info_slots *ptr_1, t_info_slots *ptr_2)
{
    int i = 0;
    int instock = false;
    while (ptr_1->forks[i] != NULL && instock == false) {
        if (my_strcmp(ptr_1->forks[i]->name, ptr_2->name) == 0)
            instock = true;
        i++;
    }
    if (instock != true) {
        ptr_1->forks[i] = ptr_2;
        ptr_1->forks[i + 1] = NULL;
    }
}

t_info_slots *connect_slots(s_var *all, char *name_1, char *name_2)
{
    t_info_slots *tmp = all->pointer_slots->next;
    t_info_slots *ptr_1 = NULL;
    t_info_slots *ptr_2 = NULL;

    while (tmp != NULL) {
        if (!my_strcmp(tmp->name, name_1))
            ptr_1 = tmp;
        if (!my_strcmp(tmp->name, name_2))
            ptr_2 = tmp;
        tmp = tmp->next;
    }
    if (ptr_2 != NULL && ptr_1 != NULL) {
        connect_between(all, ptr_1, ptr_2);
        connect_between(all, ptr_2, ptr_1);
    }
    else
        all->exit_status = 84;
}

int conditiom_travel(t_info_slots *slots, s_var *all, int j)
{
    if (slots->forks[j] != NULL &&
    !str_str(all->path, slots->forks[j]->name)
    && slots->next != NULL)
        return 1;
    return 0;
}

void ext_travel_graph(t_info_slots *slots, s_var *all, int j)
{
    if (conditiom_travel(slots, all, j) && (slots->forks_cheked[j] != 1
    || slots->distance > all->steps || slots->distance == 0)) {
        if (slots->forks[j]->next != NULL)
            slots->forks_cheked[j] = 1;
        if (slots->distance > all->steps || slots->distance == -1) {
            slots->distance = all->steps;
        }
        all->steps++;
        all->path = my_strcat(all->path, slots->forks[j]->name);
        travel_graph(slots->forks[j], all);
    }
}

void travel_graph(t_info_slots *slots, s_var *all)
{
    int j = 0;
    while (slots->forks[j] != NULL) {
        ext_travel_graph(slots, all, j);
        j++;
    }
    if (slots->forks[j] == NULL) {
        str_n_copy(all->path, index_str_str(all->path, slots->name));
        all->steps--;
    }
}