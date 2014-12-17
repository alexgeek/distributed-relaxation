#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <check.h>

#include "image.h"

/**
 * From stackoverflow:
 * http://goo.gl/lFllN
 */
int file_exists(const char *filename)
{
        struct stat buffer;
        return (stat (filename, &buffer) == 0);
}

START_TEST (test_image_exists)
{
        int size;
        const char* file = "test.bmp";
        num* mat = NULL;

        mat = matrix_alloc_square(size);
        fail_if(mat == NULL, "Could not allocate matrix.");

        matrix_init_edge(mat, size, 1, 0);
        image_write(file, mat, size);
        fail_if(!file_exists(file));
}
END_TEST

Suite* image_suite (void) {
        Suite *suite = suite_create("image");
        TCase *tcase = tcase_create("case");
        tcase_add_test(tcase, test_image_exists);
        suite_add_tcase(suite, tcase);
        return suite;
}

int main (int argc, char *argv[]) {
        int number_failed;
        Suite *suite = image_suite();
        SRunner *runner = srunner_create(suite);
        srunner_run_all(runner, CK_NORMAL);
        number_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
