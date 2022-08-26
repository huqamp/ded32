#include "equation.h"

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
* @brief Function for unit-testing
*/
void unit_test_roots(void);