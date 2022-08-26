#include "equation.h"

void input_roots(double* a, double* b, double* c) {
    printf("Enter coefficients a b c\n");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        input_clear();
        printf("Incorrect input\n"
               "Enter coefficients a b c\n");
    }

}

void output_roots(const int number_roots, const double x1, const double x2) {
    switch (number_roots) {
    case NoRoot:
        printf("No solutions\n");
        break;
    case OneRoot:
        printf("One root\n"
               "%lg\n", x1);
        break;
    case TwoRoot:
        printf("Two roots\n"
               "%lg %lg\n", x1, x2);
        break;
    case InfinityRoot:
        printf("Infinity_roots\n");
        break;
    default:
        printf("ERROR : unexpected numbers_roots, got number_roots: %d, possible_numbers_roots: %d %d %d %d\n", 
                number_roots, NoRoot, OneRoot, TwoRoot, InfinityRoot);
        break;
    }
}

int find_roots(const double a, const double b, const double c, double* x1, double* x2) {
    ASSERT(x1 != NULL);
    ASSERT(x2 != NULL);
    ASSERT(x1 != x2);
    if (compare(a, 0)) {
        if (compare(b, 0)) {
            return compare(c, 0) ? InfinityRoot : NoRoot;
        }
        else {
            if (compare(c, 0)) {
                *x1 = *x2 = 0;
            }
            else {           
                *x1 = *x2 = -c / b;
            }
            return OneRoot;
        }
    }
    else {
        if (compare(c, 0)) {
            if (compare(b, 0)) {
                *x1 = *x2 = 0;
                return OneRoot;
            }
            
            double sq = -b / a;
            if (sq < 0) { 
                *x1 = sq
                *x2 = 0
            }
            else {
                *x1 = 0;
                *x2 = sq;
            }
            return TwoRoot;
        }

        double D = b * b - 4 * a * c;
        double a2 = 2 * a;

        if (compare(D, 0)) {
            *x1 = *x2 = -b / a2;
            return OneRoot;
        }
        else if (D < 0) return NoRoot;
        else {
            double sqrt_D = sqrt(D);
            double sq1 = (-b - sqrt_D) / a2,
                   sq2 = (-b + sqrt_D) / a2;
            *x1 = min(sq1, sq2);
            *x2 = max(sq1, sq2);
            ASSERT(!(compare(*x1, *x2)));
            return TwoRoot;
        }
    }
}

