/*
** EPITECH PROJECT, 2021
** str_word_array.c
** File description:
** utilitary functions for lemin
*/

#include "./../includes/library.h"

int quantity_sentences(int size_text, char *str, char delimiter)
{
    int i = 1;
    int num_sentences = 1;

    while (i < size_text) {
        if (str[i] == delimiter || str[i] == '\0')
            num_sentences++;
        i++;
    }
    return (num_sentences);
}

int len_sentence(char *arraytext, char delimiter)
{
    int i = 0;
    while (arraytext[i] != '\0' && arraytext[i] != delimiter)
        i++;
    return (i);
}

char *save_getline_text(void)
{
    int i = 0;
    size_t n_bytes;
    char *string = NULL;
    char *getline_text = "";
    while (getline(&string, &n_bytes, stdin) != -1)
        getline_text = my_strcat(getline_text, string);
    return (getline_text);
}

char **save_words(char *arraytext, char separator)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = my_calloc(quantity_sentences(my_strlen(arraytext),
    arraytext, '\n') + 3, sizeof(char *));
    for (i; i < my_strlen(arraytext); i++, j++) {
        len = len_sentence(arraytext, '\n');
        sentences[j] = my_calloc(len * 2 + 100, sizeof(char));
        sentences[j] = my_memset(sentences[j], '\0', len * 2 + 10);
        k = 0;
        while (arraytext[i] != separator && arraytext[i] != '\0' &&
        arraytext[i] != '\n')
            sentences[j][k++] = arraytext[i++];
    }
    sentences[j] = NULL;
    return (sentences);
}
