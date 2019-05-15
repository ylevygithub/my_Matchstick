/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** game display
*/

#include "struct.h"

int end_of_line(int line, char **map, int counter)
{
    counter = 0;

    while (map[line][counter] != '\0')
        counter++;
    return (counter);
}

char **update_board(int line, int nb_match, char **map)
{
    int i = 0;
    int j = 0;

    i = line;
    j = end_of_line(line, map, j);
    while (map[i][j] != '|')
        j--;
    while (nb_match > 0) {
        map[i][j] = ' ';
        j--;
        nb_match--;
    }
    return (map);
}

int print_updated_board_game(matchstick_t *matchstick, int line, int nb_matches)
{
    if (matchstick == NULL)
        return (84);
    while ((line > matchstick->max_line || line <= 0)
    || check_line(line, matchstick->map) == 0) {
        my_putstr("Line: ");
        line = my_getint();
        switch (line)
        {
            case (-1):
                return (-1);
                break;
        }
        if (line < 0 || line == -200)
            my_putstr_error("Error: invalid input (positive number expected)\n");
        else if (line > matchstick->max_line || line == 0)
            my_putstr_error("Error: this line is out of range\n");
        else if (check_line(line, matchstick->map) == 0)
            my_putstr_error("Error: not enough matches on this line\n");
    }
    while (nb_matches == 0
    || nb_matches > check_line(line, matchstick->map)
    || nb_matches > matchstick->max_matches || nb_matches < 0) {
        my_putstr("Matches: ");
        nb_matches = my_getint();
        switch (nb_matches)
        {
            case (-1): return (-1); break;
            case (0): {
                my_putstr_error("Error: you have to remove at least one match\n");
                return (-31);
            }
        }
        if (nb_matches > matchstick->max_matches) {
            my_putstr_error("Error: you cannot remove more than ");
            my_putnbr(matchstick->max_matches);
            my_putstr_error(" matches per turn\n");
            return (-31);
        }
        else if (nb_matches > check_line(line, matchstick->map)) {
            my_putstr_error("Error: not enough matches on this line\n");
            return (-31);
        }
        else if (nb_matches < 0 || nb_matches == -200) {
            my_putstr_error("Error: invalid input (positive number expected)\n");
            return (-31);
        }
    }
    my_putstr("Player removed ");
    my_putnbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putstr("\n");
    matchstick->map = update_board(line, nb_matches, matchstick->map);
    display_map(matchstick->map);
    if (check_matches(line, matchstick->map) == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    my_putstr("\nAI's turn...\n");
    while (check_line(line, matchstick->map) == 0)
        line++;
    while (check_line(line, matchstick->map) < nb_matches)
        nb_matches = random() % matchstick->max_matches + 1;
    my_putstr("AI removed ");
    my_putnbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putstr("\n");
    matchstick->map = update_board(line, nb_matches, matchstick->map);
    display_map(matchstick->map);
    if (check_matches(line, matchstick->map) == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int game_loop(matchstick_t *matchstick, int line, int nb_matches, int return_value)
{
    while (check_matches(line, matchstick->map) != 0) {
        if (return_value != -31)
            my_putstr("\nYour turn:\n");
        if ((return_value = print_updated_board_game(matchstick, line, nb_matches)) == -31)
            return (game_loop(matchstick, line, nb_matches, -31));
        if (return_value == -1 || return_value == 1 || return_value == 2)
            return (return_value);
    }
    return (0);
}
