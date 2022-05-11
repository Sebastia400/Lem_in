/*
** EPITECH PROJECT, 2022
** find_char_array
** File description:
** find_char_array
*/

#include "../includes/library.h"

int find_char_array(char *array, char c)
{
    int i = 0;

    while (array[i] != '\0') {
        if (array[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}