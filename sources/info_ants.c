/*
** EPITECH PROJECT, 2022
** info_ants.c
** File description:
** file to get info about the ants
*/

#include "./../includes/library.h"

int save_num_ants(s_var *all)
{
    int i = 0;
    i = is_comment(all, all->arrInf, i);
    all->num_ants = my_atoi(all->arrInf[i]);
    return i;
}

void save_info_start(s_var *all, int j)
{
    char **info = NULL;

    while (my_strcmp(all->arrInf[j], "##start") != 0)
        j++;
    j++;
    if (!find_char_array(all->arrInf[j], '-')) {
        info = save_words(all->arrInf[j], ' ');
        create_slots(all->pointer_slots, my_atoi(info[2]),
        my_atoi(info[1]), info[0]);
        all->start = info[0];
    }
}

void save_info_slots(s_var *all, int i)
{
    char **info = NULL;

    while (find_char_array(all->arrInf[i], '-') != 1) {
        i = is_comment(all->arrInf, i);
        if (!find_char_array(all->arrInf[i], '-')) {
            info = save_words(all->arrInf[i], ' ');
            create_slots(all->pointer_slots, my_atoi(info[2]),
            my_atoi(info[1]), info[0]);
            all->end = info[0];
            i++;
        }
    }
}

void save_info_end(s_var *all, int j)
{
    char **info = NULL;

    while (my_strcmp(all->arrInf[j], "##end") != 0)
        j++;
    j++;
    if (!find_char_array(all->arrInf[j], '-')) {
        info = save_words(all->arrInf[j], ' ');
        create_slots(all->pointer_slots,
        my_atoi(info[2]), my_atoi(info[1]), info[0]);
        all->end = info[0];
    }
}

void save_connections(s_var *all, int i)
{
    char **info = NULL;

    while (all->arrInf[i] != NULL) {
        i = is_comment(all->arrInf, i);
        if (find_char_array(all->arrInf[i], '-')) {
            info = save_words(all->arrInf[i], '-');
            connect_slots(all, info[0], info[1]);
        }
        i++;
    }
}