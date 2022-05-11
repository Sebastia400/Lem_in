/*
** EPITECH PROJECT, 2022
** info_ants.c
** File description:
** file to get info about the ants
*/

#include "./../includes/library.h"

void *my_calloc(int nmemb, int size)
{
    void *ptr = NULL;

    if (!(ptr = malloc(nmemb * size)))
        return (NULL);
    ptr = my_memset(ptr, 0, nmemb * size);
    return (ptr);
}

int comp_str(char const *n1, char const *n2)
{
    int i = 0;

    while (n1[i] && n2[i]) {
        if (n1[i] != n2[i])
            return (n1[i] - n2[i]);
        i++;
    }
    return (0);
}

int my_strcmp(char const *n1, char const *n2)
{
    int len1 = my_strlen(n1);
    int len2 = my_strlen(n2);
    if (len1 != len2)
        return (1);
    int len = comp_str(n1, n2);

    if (len == 0 && len1 < len2)
        len = 0 - n2[len2 + 1];
    else if (len == 0 && len1 > len2)
        len = n1[len1 + 1];
    return (len);
}

void str_n_copy(char *path, int index)
{
    while (path[index] != '\0') {
        path[index] = '\0';
        index++;
    }
}

void print_array_strings(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        write(1, array[i], my_strlen(array[i]));
        if (array[i + 1] != NULL)
            my_putchar('\n');
        i++;
    }
}