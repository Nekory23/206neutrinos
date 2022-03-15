/*
** EPITECH PROJECT, 2021
** 206neutrinos
** File description:
** start
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "neutrinos.h"

static int display_help(void)
{
    printf("%s", HELP);
    return SUCCESS;
}

static bool error_handling(int ac, char **av)
{
    if (ac != 5) {
        fprintf(stderr, "Invalid number of arguments\n");
        return true;
    }
    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9') {
            fprintf(stderr, "The first argument must be a positive integer\n");
            return true;
        }
    for (int i = 2; i != ac; ++i)
        for (int j = 0; av[i][j] != '\0'; ++j) {
            if (av[i][j] == '.')
                continue;
            if (av[i][j] < '0' || av[i][j] > '9') {
                fprintf(stderr, "Arguments must be a positive number\n");
                return true;
            }
        }
    return false;
}

static void fill_data(char **av, data_t *data)
{
    data->value_nbr = atoi(av[1]);
    data->stand_dev = atof(av[4]);
    data->a_mean = atof(av[2]);
    data->h_mean = atof(av[3]);
    data->r_mean = 0;
}

int start(int ac, char **av)
{
    data_t data;

    if (ac == 2 && !strcmp(av[1], "-h"))
        return display_help();
    if (error_handling(ac, av))
        return ERROR;
    fill_data(av, &data);
    if (neutrinos(&data)) {
        fprintf(stderr, "Error while computing\n");
        return ERROR;
    }
    return SUCCESS;
}