#include <stdio.h>
#include <math.h>

/**
* @brief Function for cleaning input stream
*/
void input_clear(void);


/**
* @brief Function for comparing double numbers
* @param a first double number
* @param b second double number
* @return true if equals, false - otherwise
*/
int compare(const double a, const double b);


/**
* @brief Function for comparing roots
* @param a first root
* @param b second root
* @return true if equals, false - otherwise
*/
int compare_roots(const double a, const double b, const double epsilon);


/**
* @brief Function to find the minimum number
* @param a first number
* @param b second number
* @return minimum number
*/
double min(const double a, const double b);


/**
* @brief Function to find the maximum number
* @param a first number
* @param b second number
* @return maximum number
*/
double max(const double a, const double b);
