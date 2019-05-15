/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** functions who check the number of existent matches in one line or in the hole map
*/

#include "struct.h"

int check_line(int line, char **map)
{
    int j = 0;
    int nb_matches = 0;

    while (map[line][j] != '\0') {
        if (map[line][j] == '|') {
            nb_matches++;
        }
        j++;
    }
    return (nb_matches);
}

int check_matches(int line, char **map)
{
    int nb_matches = 0;

    line = 0;
    while (map[line] != NULL) {
        nb_matches = nb_matches + check_line(line, map);
        line++;
    }
    return (nb_matches);
}
