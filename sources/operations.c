/*
** EPITECH PROJECT, 2021
** function main
** File description:
** func1
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

void op_rra(t_node *l_a, t_variables *var)
{
    int data;
    int next;
    t_node *tmp = l_a;

    data = tmp->data;
    while (tmp->nextPtr != NULL) {
        tmp = tmp->nextPtr;
        next = tmp->data;
        tmp->data = data;
        data = next;
    }
    tmp = l_a;
    tmp->data = data;
    if (var->count_lb == 0 && check_sorted(var, l_a) == 1) {
        my_putstr("rra\n");
    } else
        my_putstr("rra ");
}

void op_rrr(t_node *l_a, t_node *l_b, t_variables *var)
{
    op_rra(l_a, var);
    op_rra(l_b, var);
    my_putstr("rrr ");
}

void op_ra(t_node *l_a, t_variables *var)
{
    int data;
    int next;
    t_node *tmp = l_a;

    data = tmp->data;
    while (tmp->nextPtr != NULL) {
        next = tmp->nextPtr->data;
        tmp->data = next;
        tmp = tmp->nextPtr;
    }
    tmp->data = data;
    if (var->count_lb == 0 && check_sorted(var, l_a) == 1) {
        my_putstr("ra\n");
    } else
        my_putstr("ra ");
}

void op_rr(t_node *l_a, t_node *l_b, t_variables *var)
{
    op_ra(l_a, var);
    op_ra(l_b, var);
    my_putstr("rr ");
}

void op_pa(t_node **l_a, t_node **l_b, t_variables *var)
{
    t_node *tmp_b = *l_b;
    t_node *a_final = malloc(sizeof(t_node));

    a_final->data = (*l_b)->data;
    a_final->nextPtr = (*l_a);
    var->count_la++;
    var->count_lb--;
    *l_a = a_final;
    *l_b = tmp_b->nextPtr;
    if (var->count_lb == 0 && check_sorted(var, (*l_a)) == 1) {
        my_putstr("pa\n");
    } else
        my_putstr("pa ");
}
