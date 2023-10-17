/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:12:30 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 22:03:07 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
# define INC_H

# define PI 3.14159265358
# define CELL_SIZE 25
# define SPEED 5 // CELL_SIZE / 5
# define HIGH 1000
# define WIDTH 2000

// Text color macros
# define COLOR_BLACK "\x1b[30m"
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_WHITE "\x1b[37m"
# define COLOR_RESET "\x1b[0m"

/*---------------------- ERRORS ------------------*/
# define ERR_ARG_COUNT "./cub3D take 1 Argument, no less no more."
# define ERR_FILE_EXT "the file should be in .cub format"

# if defined(__linux__)
#  define KEY_ESC 65307
#  define KEY_UP 5
#  define KEY_DOWN 5
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
# elif defined(__APPLE__)
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
# endif
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
/*---------*/
# include "./lib.h"
/*--------*/
# include "./utils.h"
# include "./parser.h"
# include "./raycaster.h"

#endif
