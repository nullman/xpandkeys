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

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "xpandkeys.h"

extern void print_version() {
    printf("%s %s by %s\n", PROGRAM_NAME, PROGRAM_VERSION, AUTHOR_NAME);
}

extern void print_help() {
    print_version();
    printf("Usage: %s [OPTIONS]\n", PROGRAM_NAME);
    printf("Where OPTIONS are:\n");
    printf("  -c, --config PATH  Use PATH instead of default configuration path\n");
    printf("  -v, --version      Print version and exit\n");
    printf("  -h, --help         Print help and exit\n");
}

extern void get_options(int argc, char *argv[], options_state_t *options_state) {
    options_state->exit = false;
    options_state->config_path = NULL;

    static struct option const long_options[] = {
        /* NAME       ARGUMENT            FLAG   SHORTNAME */
        { "help",     no_argument,        NULL,  'h' },
        { "version",  no_argument,        NULL,  'v' },
        { "config",   required_argument,  NULL,  'c' },
        { NULL,       0,                  NULL,  0 }
    };

    int opt;
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "hvc:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'c':
                options_state->config_path = optarg;
                break;
            case 'v':
                options_state->exit = true;
                print_version();
                return;
                break;
            case 'h':
            default:
                options_state->exit = true;
                print_help();
                return;
                break;
        }
    }
}

#if ! TEST
int main(int argc, char *argv[]) {
    options_state_t options_state;
    options_state.exit = false;
    options_state.config_path = NULL;

    get_options(argc, argv, &options_state);
    PRINTF("options_state:\n  exit: %d\n  config_path: %s\n",
           options_state.exit, options_state.config_path);
    if (options_state.exit) exit(EXIT_SUCCESS);

    exit(EXIT_SUCCESS);
}
#endif
