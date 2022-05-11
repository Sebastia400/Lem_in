/*
** EPITECH PROJECT, 2022
** str_is_digit
** File description:
** str_is_digit
*/

#include "../includes/library.h"

int str_is_digit(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}