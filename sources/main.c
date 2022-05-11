/*
** EPITECH PROJECT, 2021
** function main
** File description:
** funcmain
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

int push_swap(t_variables *var)
{
    t_node *l_a = malloc(sizeof(t_node *));
    t_node *l_b = malloc(sizeof(t_node *));

    if (error_manager(var) == 84)
        return (84);
    save(var->argc, var->argv, l_a, var);
    if (var->return_val == 84)
        return (84);
    l_a = l_a->nextPtr;
    l_b = l_b->nextPtr;
    while (check_sorted(var, l_a) != 1 && var->count_la > 1) {
        algorithm_sort(&l_a, &l_b, var);
    }
    algorithm_sort2(&l_a, &l_b, var);
    free_node(l_a, l_b);
    return (0);
}

int main(int argc, char **argv)
{
    t_variables var;

    var.count_la = (argc - 1);
    var.count_lb = 0;
    var.argc = argc;
    var.argv = argv;
    if (push_swap(&var) == 84)
        return (84);
    return (0);
}
