/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

int invalid_sentence(s_var *all, char *comment, int i)
{
    if (find_char_array(comment, '-') || str_is_digit(comment)
    || save_words(comment, ' ')[2] != NULL || comment[0] == '#')
        return (0);
    all->invalid_sentence = 1;
    return (1);
}

int is_comment(s_var *all, char **inf, int i)
{
    int res = 0;
    res = invalid_sentence(all,  inf[i], i);
    while (inf[i] != NULL && inf[i][0] == '#' ||
    (res == 1 && i == 0)) {
        if (i != 0)
            res = invalid_sentence(all,  inf[i], i);
        if (my_strcmp(inf[i], "##end") == 0
        || my_strcmp(inf[i], "##start") == 0)
            i++;
        i++;
    }
    return (i);
}

int main(int argc, char **argv)
{
    s_var *all = init_struct();
    all->pointer_slots = init_struct_slots();
    all->pointer_paths = malloc(sizeof(t_info_path *) * 100);
    for (int i = 0; i < 100; i++)
        all->pointer_paths[i] = NULL;
    all->final_steps = 1;
    save_information(all, " ");
    all->invalid_sentence = 0;
    print_output(all);
    if (all->exit_status != 84) {
        t_info_slots *tmp = all->pointer_slots->next;
        travel_graph(tmp, all);
        free(all->path);
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->distance = 100000;
        save_paths(all, tmp);
        func_move_ants(all, tmp);
    }
    return (all->exit_status);
}
