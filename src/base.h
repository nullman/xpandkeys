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

#ifndef __BASE_H
#define __BASE_H

#define MAXLEN 256
#define LENGTH(x) (sizeof(x) / sizeof(*x))

#ifdef DEBUG
#define PUTS(x) puts(x)
#define PRINTF(x, ...) printf(x, __VA_ARGS__)
#else
#define PUTS(x) ((void)0)
#define PRINTF(x, ...) ((void)0)
#endif

#endif // __BASE_H
