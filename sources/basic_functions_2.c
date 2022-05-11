/*
** EPITECH PROJECT, 2022
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"

void my_putchar(char letter)
{
    write(1, &letter, 1);
}

void my_putstr(char const *str)
{
    int len = 0;

    if (str) {
        len = my_strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}

long my_put_nbr(long nb)
{
    long n;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            n = (nb % 10);
            nb = (nb - n) / 10;
            my_put_nbr(nb);
            my_putchar(48 + n);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}

int matrix_len(char **matrix)
{
    int len = 0;

    while (matrix[len] != NULL)
        len++;
    return (len - 1);
}

int my_atoi(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return (res);
}