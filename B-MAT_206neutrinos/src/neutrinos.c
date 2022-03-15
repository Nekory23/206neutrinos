/*
** EPITECH PROJECT, 2021
** B-MAT_206neutrinos
** File description:
** neutrinos
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "neutrinos.h"

static void display_res(data_t *data)
{
    printf("%s%d\n", VAL_NBR, data->value_nbr);
    printf("%s%.2f\n", STAND_DEV, data->stand_dev);
    printf("%s%.2f\n", ARI_MEAN, data->a_mean);
    printf("%s%.2f\n", ROOT_MEAN, data->r_mean);
    printf("%s%.2f\n", HARMO_MEAN, data->h_mean);
    printf("\n");
}

static bool check_valid_input(char *buff)
{
    for (int i = 0; buff[i] != '\n'; ++i) {
        if (buff[i] == '.')
            continue;
        if (buff[i] < '0' || buff[i] > '9')
            return true;
    }
    return false;
}

bool neutrinos(data_t *data)
{
    size_t size = 1;
    char *buff = malloc(sizeof(char) * size);

    while (1) {
        printf(PROMPT);
        if (getline(&buff, &size, stdin) == EOF)
            break;
        if (!strcmp(buff, "END\n"))
            break;
        else {
            if (check_valid_input(buff)) {
                free(buff);
                return true;
            }
            compute(data, buff);
        }
        display_res(data);
    }
    free(buff);
    return false;
}