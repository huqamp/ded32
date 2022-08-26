#include <stdio.h>
#include <math.h>

#include "equation.h"

int main() {
    unit_test_roots();
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    input_roots(&a, &b, &c);
    int number_roots = find_roots(a, b, c, &x1, &x2);
    output_roots(number_roots, x1, x2);
    return 0;
}
