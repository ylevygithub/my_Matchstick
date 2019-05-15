/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** functions from my lib
*/

#include "struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nb)
{
    int i;

    if (nb < 0 && nb != -2147483648) {
        write(1, "-", 1);
        i = -nb;
        my_putnbr(i);
    }
    else if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else {
        i = nb;
        if (i >= 10)
            my_putnbr(i / 10);
        my_putchar(i % 10 + '0');
    }
    return (0);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int my_str_isnum(char *str)
{
    int i = 0;

    if (str[i] == '\0') {
        i++;
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            i++;
        else if ((str[i] >= 0 && str[i] <= 47) ||
                 (str[i] >= 58 && str[i] <= 127))
            return (0);
    }
    return (1);
}

int my_getint()
{
    char *str = malloc(sizeof(char) * 4096);
    size_t c = 32;

    if (getline(&str, &c, stdin) == -1)
        return (-1);
    if (my_str_isnotnum(str) == 0)
        return (-200);
    return (my_getnbr(str));
}
