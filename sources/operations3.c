/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func3
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

int check_sorted(t_variables *var, t_node *l_a)
{
    int i = 1;
    t_node *tmp = l_a;

    while (tmp->nextPtr != NULL && (tmp->data) <= (tmp->nextPtr->data)) {
        tmp = tmp->nextPtr;
        i++;
    }
    if (i == (var->count_la)) {
        return (1);
    }
    return (0);
}

t_node *ini_new_info_files(int num, t_variables *var)
{
    t_node *file = malloc(sizeof(t_node));

    if (file == NULL)
        var->return_val = 84;
    else
        var->return_val = 0;
    file->data = num;
    file->nextPtr = NULL;
    return file;
}

void create_new(t_node *file, int num, t_variables *var)
{
    t_node *tmp = file;

    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
    }
    tmp->nextPtr = ini_new_info_files(num, var);
}

void save(int argc, char **argv, t_node *l_a, t_variables *var)
{
    int i = 1;
    int num;

    while (i < argc) {
        num = my_getnbr(argv[i]);
        create_new(l_a, num, var);
        i++;
    }
}

void free_node(t_node *l_a, t_node *l_b)
{
    free(l_a);
    free(l_b);
}
