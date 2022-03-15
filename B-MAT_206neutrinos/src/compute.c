/*
** EPITECH PROJECT, 2021
** 206neutrinos
** File description:
** compute
*/

#include <stdio.h>

#include <math.h>
#include <stdlib.h>
#include "neutrinos.h"

static void compute_stand_dev(data_t *data, double val)
{
    data->stand_dev = pow(data->a_mean, 2) + pow(data->stand_dev, 2);
    data->stand_dev = data->stand_dev * (data->value_nbr - 1) + pow(val, 2);
    data->stand_dev /= data->value_nbr;
    data->stand_dev -= pow(((data->a_mean * (data->value_nbr - 1)) + val) / data->value_nbr, 2);
    data->stand_dev = sqrt(data->stand_dev);
}

static void compute_mean(data_t *data, double val)
{
    data->a_mean = data->a_mean * (data->value_nbr - 1) + val;
    data->a_mean /= data->value_nbr;
}

static void compute_rms(data_t *data)
{
    data->r_mean = (pow(data->a_mean, 2) + pow(data->stand_dev, 2));
    data->r_mean *= (data->value_nbr);
    data->r_mean = sqrt(data->r_mean / data->value_nbr);
}

static void compute_harmonic(data_t *data, double val)
{
    data->h_mean = ((1 / data->h_mean) * (data->value_nbr - 1)) + (1 / val);
    data->h_mean = data->value_nbr / data->h_mean;
}

void compute(data_t *data, char *buff)
{
    double new_value = atof(buff);

    data->value_nbr++;
    compute_stand_dev(data, new_value);
    compute_mean(data, new_value);
    compute_rms(data);
    compute_harmonic(data, new_value);
}