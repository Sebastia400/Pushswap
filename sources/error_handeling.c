/*
** EPITECH PROJECT, 2021
** function main
** File description:
** funcmain
*/

#include "./../include/librarie.h"
#include "./../include/structures.h"

int error_manager(t_variables *var)
{
    if (var->argc <= 1 || var->argc > 2001)
        return (84);
    return (0);
}
