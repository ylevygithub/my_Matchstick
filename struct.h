/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** struct.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct matchstick_s matchstick_t;

struct matchstick_s {
    int max_line;
    int max_matches;
    int line;
    int nb_matches;
    char **map;
    int height_max;
    int width_max;
};

void my_putchar(char );
int my_putnbr(int );
char **update_board(int , int , char **);
int check_line(int , char **);
int check_matches(int , char **);
int print_updated_board_game(matchstick_t *, int , int );
int game_loop(matchstick_t *, int , int , int );
void my_putstr(char *);
int my_str_isnum(char *);
int check_arg(int , char **);
matchstick_t *init_matchstick(char **);
char **create_line_star(char **, int );
char **write_in_tab(char **, int , int );
char **create_map(int , int );
void display_map(char **);
int my_getint();
int is_digit(char );
int my_getnbr(char *);
int end_of_line(int , char **, int );
void my_putchar_error(char );
void my_putstr_error(char *);
int my_str_isnotnum(char *);