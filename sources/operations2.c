/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func2
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

void op_pb(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_a = *l_a;
    t_node *b_final = malloc(sizeof(t_node));

    b_final->data = (*l_a)->data;
    b_final->nextPtr = (*l_b);
    var->count_lb++;
    var->count_la--;
    *l_b = b_final;
    *l_a = tmp_a->nextPtr;
    my_putstr("pb ");
}

void op_sa(t_node *l_a, t_variables *var)
{
    int valuetmp;
    t_node *tmp = l_a;

    if (var->count_la >= 2) {
        valuetmp = tmp->data;
        tmp->data = tmp->nextPtr->data;
        tmp->nextPtr->data = valuetmp;
    }
    my_putstr("sa ");
}

void op_sb(t_node *l_b, t_variables *var)
{
    int valuetmp;
    t_node *tmp = l_b;

    if (var->count_lb >= 2) {
        valuetmp = tmp->data;
        tmp->data = tmp->nextPtr->data;
        tmp->nextPtr->data = valuetmp;
    }
    my_putstr("sb ");
}

void op_sc(t_node *l_a, t_node *l_b, t_variables *var)
{
    op_sa(l_a, var);
    op_sb(l_b, var);
    my_putstr("sc ");
}
