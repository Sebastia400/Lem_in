/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <math.h>
    #include <ncurses.h>

//BASIC FUNCTIONS
int my_strlen(char const *str);
void *my_memset(void *s, int c, int n);
char *my_strcat(char *dest, char *src);
void my_putstr(char const *str);
char *my_strdup(char *str);
long my_put_nbr(long nb);
int matrix_len(char **matrix);
int my_atoi(char *str);
int my_strcmp(const char *s1, const char *s2);
void *my_calloc(int nmemb, int size);
int is_comment(s_var *all, char **array_information, int i);
int str_is_digit(char *str);
int find_char_array(char *array, char c);
void str_n_copy(char *path, int index);
void my_putchar(char letter);
void print_array_strings(char **array);
void print_sentence(char *sentence);
int str_is_digit(char *str);
int find_char_array(char *array, char c);
int invalid_sentence(s_var *all, char *comment, int i);
int index_str_str(char *string, char *to_find);
int str_str(char *string, char *to_find);

//SAVE FUNCTIONS
char *save_text(char *filepath);
char **save_words(char *arraytext, char separator);
char *save_getline_text(void);

//SAVE INFORMATION
int save_num_ants(s_var *all);
void save_info_start(s_var *all, int j);
int in_stock(s_var *all, int i, int j, char *name);
void save_info_end(s_var *all, int j);
void save_info_slots(s_var *all, int i);
void save_connections(s_var *all, int i);
void save_information(s_var *all, char *filepath);

//MOVE ANTS
void func_move_ants(s_var *all, t_info_slots *tmp);

//FIND PATHS
void find_paths(t_info_slots *slots, s_var *all, void *pointer_path);
void save_paths(s_var *all, t_info_slots *tmp);

//INITIALIZE
s_var *init_struct();
t_info_slots *init_struct_slots();
t_info_path *init_struct_path();
t_info_slots *init_linked_slots(int i, int j, char *name);
t_info_path *init_linked_path(char *name);
t_info_path *init_linked_path(char *name);

//CREATE LINKEDS
void create_prev(t_info_path *file);
void create_path(t_info_path *file, char *name);
void create_slots(t_info_slots *file, int i, int j, char *name);

//MAKE GRAPH
void travel_graph(t_info_slots *slots, s_var *all);
void str_n_copy(char *path, int index);
int index_str_str(char *string, char *to_find);
int str_str(char *string, char *to_find);
t_info_slots *connect_slots(s_var *all, char *name_1, char *name_2);
void connect_between(s_var *all, t_info_slots *ptr_1, t_info_slots *ptr_2);

//PRINT OUTPUT
void print_output(s_var *all);

#endif
