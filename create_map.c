/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** functions who create the map
*/

#include "struct.h"

char **create_line_star(char **map, int index)
{
    int i = 0;

    while (map[index][i] != '\0') {
        map[index][i] = '*';
        i++;
    }
    return (map);
}

char **write_in_tab(char **map, int height_max, int width_max)
{
    int index = 1;
    int begin = 0;
    int nb_match;

    map = create_line_star(map, 0);
    map = create_line_star(map, height_max - 1);
    while (index <= height_max - 2) {
        map[index][0] = '*';
        map[index][width_max - 1] = '*';
        nb_match = (index * 2) - 1;
        begin = (((width_max - 2) - nb_match) / 2) + 1;
        while (nb_match > 0) {
            map[index][begin] = '|';
            begin++;
            nb_match--;
        }
        index++;
    }
    return (map);
}

char **create_map(int height_max, int width_max)
{
    int i = 0;
    int j = 0;
    char **map = malloc(sizeof(char *) * height_max + 1);

    if (map == NULL)
        return (NULL);
    while (i < height_max) {
        map[i] = malloc(sizeof(char) * width_max + 1);
        if (map[i] == NULL)
            return (NULL);
        while (j < width_max) {
            map[i][j] = ' ';
            j++;
        }
        j = 0;
        i++;
    }
    map = write_in_tab(map, height_max, width_max);
    return (map);
}
