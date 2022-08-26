#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "other.h"

#ifndef H_EQUATION
#define H_EQUATION
 
enum NumbersRoot {
    NoRoot        = 0,
    OneRoot       = 1, 
    TwoRoot       = 2, 
    InfinityRoot  = 3,
};

#define ASSERT(condition)                   \
    if(!(condition))                        \
        printf("Error in %s in %d line\n",  \
                #condition, __LINE__);      


/**
* @brief Function for entering coefficients
* @param a first coefficient
* @param b second coefficient
* @param c third coefficient
*/
void input_roots(double* a, double* b, double* c);


/**
* @brief Function for displaying roots
* @param x1 first root
* @param x2 second root
*/
void output_roots(const int number_roots, const double x1, const double x2);


/**
* @brief Function for solving quadratic equations
* @param a - first coefficient
* @param b - second coefficient
* @param c - third coefficient
* @return x1, x2 - first root, second root
*/
int find_roots(const double a, const double b, const double c, double* x1, double* x2);

#endif