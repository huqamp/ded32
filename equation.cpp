#include <math.h>
#include <stdio.h>
#include <assert.h>

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

struct TestUnit {
    double a, b, c;
    int number_roots;
    double first_root;
    double second_root;
};

void input_clear() {
    while (getchar() != '\n');
}

void input_roots(double* a, double* b, double* c) {
    printf("Enter coefficients\n");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        input_clear();
        printf("Incorrect input\n"
               "Enter coefficients\n");
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
        assert(0 && "WTF");
        break;
    }
}

int compare(const double a, const double b) {
    const double eps = 1E-6;
    return (fabs(a - b) < eps);
}

int compare_roots(double a, double b) {
    const double eps = 1E-2;
    return (fabs(a - b) < eps);
}

double min(const double a, const double b) {
    return a > b ? b : a;
}

double max(const double a, const double b) {
    return a > b ? a : b;
}

int find_roots(const double a, const double b, const double c, double* x1, double* x2) {
    if (compare(a, 0)) {
        if (compare(b, 0)) {
            return compare(c, 0) ? InfinityRoot : NoRoot;
        }
        else {
            if (compare(c, 0)) *x1 = *x2 = 0;
            else               *x1 = *x2 = -c / b;
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
            *x1 = min(sq, 0);
            *x2 = max(sq, 0);
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

void unit_test_roots(void) {
    struct TestUnit array[] = {0, 0,  0, InfinityRoot,         NAN,       NAN,
                               3, 2,  100, NoRoot,         NAN,       NAN,
                               0, 5,  0, OneRoot,              0,       0,
                               0, 5, -5, OneRoot,              1,       1,
                               1, 2,  1, OneRoot,             -1,      -1,
                               2, 5,  2, TwoRoot,             -2,      -0.5,
                               1, 3,  2, TwoRoot,             -2,      -1,
                               1, 4,  1, TwoRoot,             -3.732, -0.267};

    int errors = 0, all = sizeof(array) / sizeof (array[0]);
    double x1 = NAN, x2 = NAN;

    for (int i = 0; i < all; i++) {
        x1 = NAN, x2 = NAN;
        int number_tests_roots = find_roots(array[i].a, array[i].b, array[i].c, &x1, &x2);
        if (array[i].number_roots != number_tests_roots) {
            printf("Warning, test=%d, true_root_numbers = %d, root_numbers = %d\n", i + 1, array[i].number_roots, number_tests_roots);
            errors++;
        }
        else if ((array[i].number_roots != InfinityRoot && array[i].number_roots != NoRoot) && (!(compare_roots(array[i].first_root, x1)) || !(compare_roots(array[i].second_root, x2)))) {
            printf("Warning, test=%d, one_root = %lg, second_root = %lg, true_first_root = %lg, true_second_root = %lg\n", i + 1, x1, x2, array[i].first_root, array[i].second_root);
            errors++;
        }
        else printf("Accept, test=%d\n", i + 1);
    }
    printf("Accepted - %d, errors - %d\n", all - errors, errors);



}
