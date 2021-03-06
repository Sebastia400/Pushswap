/*
** EPITECH PROJECT, 2021
** function main
** File description:
** start the project
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

void find_closer3(t_variables *var, t_node **l_a, t_node **l_b)
{
    if (var->side == 1) {
        while (var->pos_to_move > 0) {
            op_rra(*l_a, var);
            var->pos_to_move--;
        }
    } else if (var->side == 0) {
        while (var->pos_to_move > 0) {
            op_ra(*l_a, var);
            var->pos_to_move--;
        }
    }
    op_pb(l_a, l_b, var);
    var->side = 0;
}

void find_closer2(t_variables *var, t_node **l_a, t_node **l_b)
{
    if (var->tmp_big <= var->tmp_small) {
        var->side = var->side2;
        var->pos_to_move = var->tmp_big;
    } else if (var->tmp_big > var->tmp_small) {
        var->side = var->side1;
        var->pos_to_move = var->tmp_small;
    }
}

void find_closer(t_variables *var, t_node **l_a, t_node **l_b)
{
    var->pos_to_move = 0;
    var->tmp_small = var->pos_smaller;
    var->tmp_big = var->pos_bigger;

    var->side1 = 0;
    var->side2 = 0;
    if ((var->count_la / 2) < var->pos_smaller) {
        var->tmp_small = var->count_la - var->pos_smaller;
        var->side1 = 1;
    }
    if ((var->count_la / 2) < var->pos_bigger) {
        var->tmp_big = var->count_la - var->pos_bigger;
        var->side2 = 1;
    }
    find_closer2(var, l_a, l_b);
    find_closer3(var, l_a, l_b);
}

void algorithm_sort(t_node **l_a, t_node **l_b, t_variables *var)
{
    int pos = 0;
    t_node *tmp_a = *l_a;

    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    while (tmp_a != NULL) {
        if (tmp_a->data < var->smaller) {
            var->smaller = tmp_a->data;
            var->pos_smaller = pos;
        }
        if (tmp_a->data > var->bigger){
            var->bigger = tmp_a->data;
            var->pos_bigger = pos;
        }
        pos++;
        tmp_a = tmp_a->nextPtr;
    }
    find_closer(var, l_a, l_b);
}

void algorithm_sort2(t_node **l_a, t_node **l_b, t_variables *var)
{
    int pos = 0;
    t_node *tmp_a = *l_a;

    var->smaller = (*l_a)->data;
    var->bigger = (*l_a)->data;
    var->pos_smaller = 0;
    var->pos_bigger = 0;
    while (var->count_lb != 0) {
        op_pa(l_a, l_b, var);
        if ((*l_a)->data > (*l_a)->nextPtr->data)
            op_ra(*l_a, var);
    }
}
