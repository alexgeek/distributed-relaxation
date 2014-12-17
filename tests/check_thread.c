#include <stdlib.h>
#include <check.h>

#include "thread.h"

START_TEST (test_globals_create)
{
        int dimension, precision, threads;
        dimension = 10;
        precision = 0.001;
        threads = 8;

        global* g = create_globals(dimension, precision, threads);

        ck_assert(dimension == g->dimension);
        ck_assert(precision == g->precision);
        ck_assert(threads == g->threads);
        ck_assert(g->relaxed == 0);
        ck_assert(g->completed == 0);

        fail_if(g->current == NULL);
        fail_if(g->next == NULL);

        free_globals(g);
}
END_TEST

START_TEST (test_thread_params)
{
        int dimension, precision, threads;
        dimension = 10;
        precision = 0.001;
        threads = 8;

        int from, to;
        from = 2;
        to = 4;
        global* g = create_globals(dimension, precision, threads);
        params* p = create_params(g, from, to);
        ck_assert(p->from = from);
        ck_assert(p->to = to);
        fail_if(p->g == NULL);
}
END_TEST

Suite* thread_suite (void) {
        Suite *suite = suite_create("thread");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_globals_create);
        tcase_add_test(tcase, test_thread_params);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = thread_suite();
        SRunner *runner = srunner_create(suite);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
