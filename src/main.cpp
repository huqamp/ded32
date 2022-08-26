// #define TESTING

#include "equation.h"
#include "testing.h"

int main() {
#ifdef TESTING
    unit_test_roots();
    return 0;
#endif // TESTING
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    input_roots(&a, &b, &c);
    int number_roots = find_roots(a, b, c, &x1, &x2);
    output_roots(number_roots, x1, x2);
    return 0;
}


