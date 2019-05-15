/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** error handling
*/

#include "struct.h"

void  my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
    my_putchar_error(str[nb]);
    nb++;
    }
}
