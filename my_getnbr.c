/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get the number of the string 
*/

#include "struct.h"

int is_digit(char strdigit)
{
    if (strdigit < '0' || strdigit > '9')
        return 0;
    return 1;
}

int my_getnbr(char *str)
{
    int i, num, readnum, neg;

    i = num = readnum = 0;
    neg = 1;
    while (str[i]) {
        if (is_digit(str[i])) {
            num = 10 * num + (str[i] - '0');
            readnum = 1;
        }
        else {
            if (readnum == 1)
                return (neg * num);
            neg = 1;
            if (str[i] == '-')
                neg = -1;
        }
        i++;
    }
    return (num);
}
