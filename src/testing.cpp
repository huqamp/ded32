#include "testing.h"

void unit_test_roots(void) {
    struct TestUnit array[] = {0, 0,  0,   InfinityRoot,         NAN,     NAN,
                               3, 2,  100, NoRoot,               NAN,     NAN,
                               0, 5,  0,   TwoRoot,              0,       0,
                               0, 5, -5,   OneRoot,              1,       1,
                               1, 2,  1,   OneRoot,             -1,      -1,
                               2, 5,  2,   TwoRoot,             -2,      -0.5,
                               1, 3,  2,   TwoRoot,             -1,      -1,
                               1, 4,  1,   TwoRoot,             -3.732,  -0.267};

    int errors = 0, numbers_tests = sizeof(array) / sizeof (array[0]);
    double x1 = NAN, x2 = NAN;
    const double epsilon_roots = 1E-2;
    for (int i = 0; i < numbers_tests; i++) {
        x1 = NAN, x2 = NAN;
        int number_tests_roots = find_roots(array[i].a, array[i].b, array[i].c, &x1, &x2);
        if (array[i].number_roots != number_tests_roots) {
            printf("Warning, test=%d, true_root_numbers = %d, root_numbers = %d\n", i + 1, array[i].number_roots, number_tests_roots);
            errors++;
        }
        else if ((array[i].number_roots != InfinityRoot && array[i].number_roots != NoRoot) && (!(compare_roots(array[i].first_root, x1, epsilon_roots)) 
                                                                                             || !(compare_roots(array[i].second_root, x2, epsilon_roots)))) {
            printf("Warning, test=%d, one_root = %lg, second_root = %lg, true_first_root = %lg, true_second_root = %lg\n", i + 1, x1, x2, array[i].first_root, array[i].second_root);
            errors++;
        }
        else printf("Accept, test=%d\n", i + 1);
    }
    printf("Accepted - %d, errors - %d\n", numbers_tests - errors, errors);



}
