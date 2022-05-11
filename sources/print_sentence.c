/*
** EPITECH PROJECT, 2022
** print sentence
** File description:
** print_sentence
*/

#include "../includes/library.h"

void print_sentence(char *sentence)
{
    int i = 0;

    while (sentence[i] != '\0' && sentence[i] != '\n'
    && (sentence[i] != '#' || i <= 1)) {
        my_putchar(sentence[i]);
        i++;
    }
}