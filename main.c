/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main
*/

#include "struct.h"

int check_arg(int ac, char **av)
{
    if (ac != 3 || !my_str_isnum(av[1]) || !my_str_isnum(av[2]))
        return (-1);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100 || my_getnbr(av[2]) < 1)
        return (-1);
    return (0);
}

matchstick_t *init_matchstick(char **av)
{
    matchstick_t *matchstick;

    matchstick = malloc(sizeof(matchstick_t));
    if (matchstick == NULL)
        return (NULL);
}

void display_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        my_putstr(map[i]);
        my_putstr("\n");
        i++;
    }
}

int main(int ac, char **av)
{
    matchstick_t *matchstick;
    int return_value;

    if (check_arg(ac, av) == -1)
        return (84);
    matchstick = init_matchstick(av);
    if (matchstick == NULL)
        return (84);
    matchstick->max_line = my_getnbr(av[1]);
    matchstick->max_matches = my_getnbr(av[2]);
    matchstick->height_max = matchstick->max_line + 2;
    matchstick->width_max = matchstick->max_line * 2 + 1;
    matchstick->map = create_map(matchstick->height_max, matchstick->width_max);
    display_map(matchstick->map);
    return_value = game_loop(matchstick, matchstick->line, matchstick->nb_matches, 0);
    if (return_value == 0 || return_value == 1 || return_value == 2)
        return (return_value);
    if (return_value == -1)
        return (0);
    free(matchstick);
    return (0);
}
