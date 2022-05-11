/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-victor.gonzalez
** File description:
** main.c
*/

#include "./../includes/library.h"

void clean_info(char **info)
{
    int i = 0;
    int j = 0;

    while (info[i] != NULL) {
        while (info[i][j] != '\0' && info[i][j] != ' ' && info[i][j] != '#')
            j++;
        info[i][j] = '\0';
        i++;
    }
}

void save_connections(s_var *all, int i)
{
    char **info = NULL;
    int num_conections = 0;

    while (all->inf[i] != NULL && all->exit_status != 84 &&
    invalid_sentence(all, all->inf[i], i) == 0 &&
    all->invalid_sentence == 0) {
        i = is_comment(all, all->inf, i);
        if (all->inf[i] != NULL &&
        find_char_array(all->inf[i], '-')) {
            info = save_words(all->inf[i], '-');
            clean_info(info);
            connect_slots(all, info[0], info[1]);
            num_conections++;
        }
        i++;
    }
    if (num_conections == 0)
        all->exit_status = 84;
}

void save_information(s_var *all, char *filepath)
{
    char *text = save_getline_text();
    char *arraytext = malloc(sizeof(char) * 10000 + 1);
    int i = 0;
    int j = 0;
    char **info = NULL;
    char **names = malloc(sizeof(char *) * 5);

    all->inf = save_words(text, '\n');
    i = save_num_ants(all);
    save_info_start(all, i);
    save_info_slots(all, i + 1);
    save_info_end(all, 0);
    if (all->exit_status != 84) {
        save_connections(all, i);
        all->start = all->pointer_slots->next->name;
        t_info_slots *tmp = all->pointer_slots->next;
        all->path = malloc(sizeof(char) * 100);
        all->path = my_strdup(all->start);
        all->steps = 0;
    }
}