/******************************************************************************
 * xpandkeys: Convert abbreviations to longer strings under X11.              *
 *                                                                            *
 * Copyright (C) 2022 Kyle W T Sherman                                        *
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

#ifndef __XPANDKEYS_H
#define __XPANDKEYS_H

#include <stdio.h>
#include "base.h"

#define PROGRAM_NAME    "xpandkeys"
#define PROGRAM_VERSION "1.0.0"
#define AUTHOR_NAME     "Kyle W T Sherman"
#define CONFIG_HOME_ENV "XDG_CONFIG_HOME"
#define CONFIG_PATH     "xpandkeys/xpandkeys.conf"

typedef struct {
    bool exit;
    char *config_path;
} options_state_t;

extern char *config_path;
extern char  config_file[MAXLEN];

extern void print_version();
extern void print_help();
extern void get_options(int argc, char *argv[], options_state_t *options_state);

#endif // __XPANDKEYS_H
