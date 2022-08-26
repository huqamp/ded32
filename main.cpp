#define NDEBUG

#include "equation.h"
#include "testing.h"

int main() {
#ifndef NDEBUG
    unit_test_roots();
#else  // NDEBUG
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    input_roots(&a, &b, &c);
    int number_roots = find_roots(a, b, c, &x1, &x2);
    output_roots(number_roots, x1, x2);
#endif // NDEBUG
    return 0;
}


