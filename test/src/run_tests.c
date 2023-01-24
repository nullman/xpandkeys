/******************************************************************************
 * xpandkeys: Convert abbreviations to longer strings under X11.              *
 *                                                                            *
 * Copyright © 2021-2023 Kyle W T Sherman                                     *
 *                                                                            *
 * Author: Kyle W T Sherman <kylewsherman@gmail.com>                          *
 * URL: https://github.com/nullman/xpandkeys                                  *
 * Created: 2021-12-26                                                        *
 * Version: 1.0.0                                                             *
 ******************************************************************************/

/******************************************************************************
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation; either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program; if not, write to the Free Software Foundation, Inc.,    *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                *
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "xpandkeys.h"

int tests_run = 0;

static char * test_get_string() {
    mu_assert("get_string should return 'Hello World!'",
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
