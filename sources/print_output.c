/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int print_num_ants(s_var *all, int i)
{
    if (all->num_ants > 0 && !invalid_sentence(all, all->inf[i], i)) {
        my_putstr("#number_of_ants\n");
        my_put_nbr(all->num_ants);
        my_putchar('\n');
        i++;
    }
    return (i);
}

int print_rooms(s_var *all, int i)
{
    my_putstr("#rooms\n");
    while (all->inf[i] != NULL && !find_char_array(all->inf[i], '-')
    && all->invalid_sentence == 0 && !invalid_sentence(all, all->inf[i], i)) {
        if (all->inf[i][0] == '#' && all->inf[i][1] == '#' ||
        all->inf[i][0] != '#' && all->inf[i][1] != '#') {
            print_sentence(all->inf[i]);
            my_putstr("\n");
        }
        i++;
    }
    return (i);
}

int print_tunnels(s_var *all, int i)
{
    my_putstr("#tunnels\n");
    while (all->inf[i] != NULL && all->invalid_sentence == 0
    && !invalid_sentence(all, all->inf[i], i)){
        if (all->inf[i][0] == '#' && all->inf[i][1] == '#' ||
        all->inf[i][0] != '#' && all->inf[i][1] != '#') {
            print_sentence(all->inf[i]);
            my_putstr("\n");
        }
        i++;
    }
    return (i);
}

void print_output(s_var *all)
{
    int i = 0;

    invalid_sentence(all, all->inf[i], i);
    while (all->inf[i] != NULL && !invalid_sentence(all, all->inf[i], i)
    && all->inf[i][0] == '#' && all->inf[i][1] != '#')
        i++;
    i = print_num_ants(all, i);
    if (all->inf[i] != NULL && !invalid_sentence(all, all->inf[i], i)
    && all->invalid_sentence == 0)
        i = print_rooms(all, i);
    if (all->inf[i] != NULL && !invalid_sentence(all, all->inf[i], i)
    && all->invalid_sentence == 0)
        i = print_tunnels(all, i);
    if (all->exit_status == 0)
        my_putstr("#moves\n");
}