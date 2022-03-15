/*
** EPITECH PROJECT, 2021
** B-MAT_206neutrinos
** File description:
** test_compute
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "neutrinos.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(compute, nbr_of_values, .init=redirect_all_stdout)
{
    data_t data;
    char *buffer = "299042\n";

    data.value_nbr = 12000;
    data.stand_dev = 4363;
    data.a_mean = 297514;
    data.h_mean = 297912;
    data.r_mean = 0;

    compute(&data, buffer);
    cr_assert_eq(data.value_nbr, 12001);
}

Test(compute, standard_dev, .init=redirect_all_stdout)
{
    data_t data;
    char *buffer = "299042\n";

    data.value_nbr = 12000;
    data.stand_dev = 4363;
    data.a_mean = 297514;
    data.h_mean = 297912;
    data.r_mean = 0;

    compute(&data, buffer);
    cr_assert_float_eq_op_(data.stand_dev, 4362.84, 0.01);
}

Test(compute, arithmetic_mean, .init=redirect_all_stdout)
{
    data_t data;
    char *buffer = "299042\n";

    data.value_nbr = 12000;
    data.stand_dev = 4363;
    data.a_mean = 297514;
    data.h_mean = 297912;
    data.r_mean = 0;

    compute(&data, buffer);
    cr_assert_float_eq_op_(data.a_mean, 297514.13, 0.01);
}

Test(compute, root_mean_square, .init=redirect_all_stdout)
{
    data_t data;
    char *buffer = "299042\n";

    data.value_nbr = 12000;
    data.stand_dev = 4363;
    data.a_mean = 297514;
    data.h_mean = 297912;
    data.r_mean = 0;

    compute(&data, buffer);
    cr_assert_float_eq_op_(data.r_mean, 297546.11, 0.01);
}

Test(compute, harmonic_mean, .init=redirect_all_stdout)
{
    data_t data;
    char *buffer = "299042\n";

    data.value_nbr = 12000;
    data.stand_dev = 4363;
    data.a_mean = 297514;
    data.h_mean = 297912;
    data.r_mean = 0;

    compute(&data, buffer);
    cr_assert_float_eq_op_(data.h_mean, 297912.09, 0.01);
}