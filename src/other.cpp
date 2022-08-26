#include "other.h"

void input_clear() {
    while (getchar() != '\n');
}

int compare(const double a, const double b) {
    const double eps = 1E-6;
    return compare_roots(a, b, eps);
}

int compare_roots(const double a, const double b, const double epsilon) {
    return (fabs(a - b) < epsilon);
}

double min(const double a, const double b) {
    return a > b ? b : a;
}

double max(const double a, const double b) {
    return a > b ? a : b;
}