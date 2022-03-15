/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef NEUTRINOS_H_
#define NEUTRINOS_H_

/* INCLUDE */
#include <stdbool.h>

/* STRUCTURE */
typedef struct data_s {
    int value_nbr;
    double stand_dev;
    double a_mean;
    double r_mean;
    double h_mean;
} data_t;

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

static const char HELP[] =  "USAGE\n" \
                            "    ./206neutrinos n a h sd\n" \
                            "\nDESCRIPTION\n" \
                            "    n    number of values\n" \
                            "    a    arithmetic mean\n" \
                            "    h    harmonic mean\n" \
                            "    sd   standard deviation\n";

static const char PROMPT[] = "Enter next value: ";
static const char VAL_NBR[] = "    Number of values:\t";
static const char STAND_DEV[] = "    Standard deviation:\t";
static const char ARI_MEAN[] = "    Arithmetic mean:\t";
static const char ROOT_MEAN[] = "    Root mean square:\t";
static const char HARMO_MEAN[] = "    Harmonic mean:\t";

/* PROTOTYPE */
int start(int ac, char **av);
bool neutrinos(data_t *data);
void compute(data_t *data, char *buff);

#endif /* !MAIN_H_ */
