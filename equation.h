#include <stdio.h>


/**
* @brief Struct for unit-testing
* @param a first coefficient
* @param b second coefficient
* @param c third coefficient
* @param number_roots true_number_roots
* @param first_root true_first_root
* @param second_root true_second_root
*/
struct TestUnit {
    double a;
    double b;
    double c;
    int number_roots;
    double first_root;
    double second_root;
};


/**
* @brief Function for cleaning input stream
*/
void input_clear(void);


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
void output_roots(int number_roots, double x1, double x2);


/**
* @brief Function for comparing double numbers
* @param a first double number
* @param b second double number
* @return true if equals, false - otherwise
*/
int compare(double a, double b);


/**
* @brief Function for comparing roots
* @param a first root
* @param b second root
* @return true if equals, false - otherwise
*/
int compare_roots(const double a, const double b);


/**
* @brief Function for solving quadratic equations
* @param a - first coefficient
* @param b - second coefficient
* @param c - third coefficient
* @return x1, x2 - first root, second root
*/
int find_roots(double a, double b, double c, double* x1, double* x2);


/**
* @brief Function for unit-testing
*/
void unit_test_roots(void);


/**
* @brief Function to find the minimum number
* @param a first number
* @param b second number
* @return minimum number
*/
double min(double a, double b);


/**
* @brief Function to find the maximum number
* @param a first number
* @param b second number
* @return maximum number
*/
double max(double a, double b);
