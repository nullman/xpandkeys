#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "xpandkeys.h"

int tests_run = 0;

static char * test_get_string() {
    mu_assert("get_string did not return 'Hello World!'",
              !strcmp("Hello World!", get_string()));
    return 0;
}

static char * all_tests() {
    mu_run_test(test_get_string);
    return 0;
}

int main(int argc, char *argv[]) {
    char *result = all_tests();
    if (result != 0) {
        printf("Error: %s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
