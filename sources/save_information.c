/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int save_num_ants(s_var *all)
{
    int i = 0;
    i = is_comment(all, all->inf, 0);
    if (all->inf[i] != NULL && str_is_digit(all->inf[i]) > 0
    && !find_char_array(all->inf[i], '-') && all->invalid_sentence == 0)
        all->num_ants = my_atoi(all->inf[i]);
    else
        all->exit_status = 84;
    return i;
}

void save_info_start(s_var *all, int j)
{
    char **info = NULL;

    while (all->inf[j] != NULL &&
    my_strcmp(all->inf[j], "##start") != 0
    && all->invalid_sentence == 0)
        j++;
    j++;
    if (all->inf[j] != NULL &&
    !find_char_array(all->inf[j], '-') &&
    all->inf[j][0] != '#' && invalid_sentence(all,
    all->inf[j], j) == 0 && all->invalid_sentence == 0) {
        info = save_words(all->inf[j], ' ');
        create_slots(all->pointer_slots, my_atoi(info[2]),
        my_atoi(info[1]), info[0]);
        all->start = info[0];
    }
    else
        all->exit_status = 84;
}

int in_stock(s_var *all, int i, int j, char *name)
{
    t_info_slots *tmp = all->pointer_slots->next;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0
        || (tmp->pos_x == j && tmp->pos_y == i))
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

void save_info_slots(s_var *all, int i)
{
    char **info = NULL;

    while (all->inf[i] != NULL && all->exit_status != 84
    && find_char_array(all->inf[i], '-') != 1 &&
    all->invalid_sentence == 0) {
        i = is_comment(all, all->inf, i);
        if (all->inf[i] != NULL &&
        !find_char_array(all->inf[i], '-')) {
            info = save_words(all->inf[i], ' ');
            if (matrix_len(info) == 2 && in_stock(all, my_atoi(info[2]),
            my_atoi(info[1]), info[0]))
                create_slots(all->pointer_slots, my_atoi(info[2]),
                my_atoi(info[1]), info[0]);
            else
                all->exit_status = 84;
            i++;
        }
    }
}

void save_info_end(s_var *all, int j)
{
    char **info = NULL;

    while (all->inf[j] != NULL &&
    my_strcmp(all->inf[j], "##end") != 0)
        j++;
    j++;
    if (all->inf[j] != NULL && all->inf[j][0] != '#' &&
    !find_char_array(all->inf[j], '-') &&
    invalid_sentence(all, all->inf[j], j) == 0 &&
    all->invalid_sentence == 0) {
        info = save_words(all->inf[j], ' ');
        if (in_stock(all, my_atoi(info[2]), my_atoi(info[1]), info[0])) {
            create_slots(all->pointer_slots, my_atoi(info[2]),
            my_atoi(info[1]), info[0]);
            all->end = info[0];
        } else
            all->exit_status = 84;
    } else
        all->exit_status = 84;
}
