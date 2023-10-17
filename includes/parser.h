/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:32:20 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 21:40:34 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_textures;

typedef struct s_game
{
	char		**file_lines;
	int			floor_color;
	int			ceil_color;
	t_textures	textures;
	char		**map;
}				t_game;

t_game			*parser(int ac, char *argv[]);
bool			check_map(char **map);
void			check_arguments(int ac, char *av[]);
void			skip_lines(char **lines, int *i, int should_exit);
#endif
