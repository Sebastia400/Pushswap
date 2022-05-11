/*
** EPITECH PROJECT, 2021
** Lib_pushswap
** File description:
** pushlib
*/

#ifndef LIBRARIES_H_
    #define LIBRARIES_H_

    #include "./structures.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

void op_rra(t_node *l_a, t_variables *var);
void op_rrr(t_node *l_a, t_node *l_b, t_variables *var);
void op_ra(t_node *l_a, t_variables *var);
void op_rr(t_node *l_a, t_node *l_b, t_variables *var);
void op_pa(t_node **l_a, t_node **l_b, t_variables *var);
void op_pb(t_node **l_a, t_node **l_b, t_variables *var);
void op_sa(t_node *l_a, t_variables *var);
void op_sb(t_node *l_b, t_variables *var);
void op_sc(t_node *l_a, t_node *l_b, t_variables *var);
void printlinked(t_node *file);
int check_sorted(t_variables *var, t_node *l_a);
t_node *ini_new_info_files(int num, t_variables *var);
void create_new(t_node *file, int num, t_variables *var);
void save(int argc, char **argv, t_node *l_a, t_variables *var);
void free_node(t_node *l_a, t_node *l_b);
int find_biggest_nbr(t_node *l_a);
int get_last_value(t_node *l_a);
void find_closer(t_variables *var, t_node **l_a, t_node **l_b);
void algorithm_sort(t_node **l_a, t_node **l_b, t_variables *var);
void algorithm_sort2(t_node **l_a, t_node **l_b, t_variables *var);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
int find_biggest_nbr(t_node *l_a);
int get_last_value(t_node *l_a);
int error_manager(t_variables *var);

#endif
