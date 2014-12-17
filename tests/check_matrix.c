#include <stdlib.h>
#include <check.h>

#include "matrix.h"

START_TEST (test_mat_alloc)
{
        int width = 10;
        int height = 25;

        // test with rectangular
        num* mat = NULL;
        mat = matrix_alloc(width, height);
        fail_if(mat == NULL, "Could not allocate matrix.");


        // test square
        mat = NULL;
        mat = matrix_alloc_square(width);
        fail_if(mat == NULL, "Could not allocate square matrix.");
}
END_TEST

START_TEST (test_mat_init)
{
        int size = 3;
        num* mat = NULL;

        // mats to test against
        num test_zero[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        num test_edge[9] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

        // the mat to test
        mat = matrix_alloc_square(size);

        // test init all to 0
        int i;
        matrix_init_to(mat, size, 0);
        for (i = 0; i < size*size; i++)
          ck_assert(mat[i] == test_zero[i]);

        // test init 1 to edges, 0 to inner vals
        mat = matrix_alloc_square(size);
        matrix_init_edge(mat, size, 1, 0); // edge val, inner val
        for (i = 0; i < size*size; i++)
          ck_assert(mat[i] == test_edge[i]);
}
END_TEST

Suite* matrix_suite (void) {
        Suite *suite = suite_create("matrix");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_mat_init);
        tcase_add_test(tcase, test_mat_alloc);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = matrix_suite();
        SRunner *runner = srunner_create(suite);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
