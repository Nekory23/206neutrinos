/*
** EPITECH PROJECT, 2021
** 206neutrinos
** File description:
** test_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "neutrinos.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(testerror, error1, .init=redirect_all_stdout)
{
    int ac = 1;
    char *av[] = {"\0"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error2, .init=redirect_all_stdout)
{
    int ac = 5;
    char *av[] = {"\0", "-2000"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(testerror, error3, .init=redirect_all_stdout)
{
    int ac = 5;
    char *av[] = {"\0", "2000", "-50"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(test_error, too_many_args, .init=redirect_all_stdout)
{
    int ac = 8;
    char *av[] = {"\0", "2000", "-50"};

    cr_assert_eq(start(ac, av), ERROR);
}

Test(help, help, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"\0", "-h"};

    cr_assert_eq(start(ac, av), SUCCESS);
}