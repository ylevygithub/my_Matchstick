/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** lib functions
*/

#include "struct.h"

int my_str_isnotnum(char *str)
{
    int i = 0;

    if (str[i] == '\0') {
        i++;
        return (0);
    }
    while (str[i] != '\0') {
        if ((str[i] >= 0 && str[i] <= 47) ||
                 (str[i] >= 58 && str[i] <= 127))
            i++;
        else if (str[i] >= 48 && str[i] <= 57)
            return (-1);
    }
    return (0);
}