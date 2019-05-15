/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

void  my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb++;
    }
}
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
