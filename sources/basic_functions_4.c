/*
** EPITECH PROJECT, 2022
** info_ants.c
** File description:
** file to get info about the ants
*/

#include "./../includes/library.h"

int str_str(char *string, char *to_find)
{
    int i = 0;
    int j = 0;
    int x = 0;

    while (string[i] != '\0') {
        if (string[i] == to_find[x])
            x++;
        else
            x = 0;
        if (my_strlen(to_find) == x)
            return (1);
        i++;
    }
    return (0);
}

int index_str_str(char *string, char *to_find)
{
    int i = 0;
    int j = 0;
    int x = 0;

    while (string[i] != '\0') {
        if (string[i] == to_find[x])
            x++;
        else
            x = 0;
        if (my_strlen(to_find) == x)
            return (i - x + 1);
        i++;
    }
    return (0);
}