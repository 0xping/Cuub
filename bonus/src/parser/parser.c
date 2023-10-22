/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:13:26 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 17:43:57 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	add_item(char **splitted, t_game *game, int *colors)
{
	if (!ft_strcmp(splitted[0], "C"))
	{
		game->ceil_color = get_color_from_string(splitted[1]);
		*colors += 1;
	}
	else if (!ft_strcmp(splitted[0], "F"))
	{
		game->floor_color = get_color_from_string(splitted[1]);
		*colors += 1;
	}
	else if (!ft_strcmp(splitted[0], "NO"))
		game->textures.north = ft_strdup(splitted[1]);
	else if (!ft_strcmp(splitted[0], "SO"))
		game->textures.south = ft_strdup(splitted[1]);
	else if (!ft_strcmp(splitted[0], "WE"))
		game->textures.west = ft_strdup(splitted[1]);
	else if (!ft_strcmp(splitted[0], "EA"))
		game->textures.east = ft_strdup(splitted[1]);
	else if (!ft_strcmp(splitted[0], "DO"))
		game->textures.door = ft_strdup(splitted[1]);
}

char	**fill_map(char **lines, int *i)
{
	char	*map;
	char	*tmp;
	char	**sp;

	skip_lines(lines, i, 0);
	map = 0;
	while (lines[*i] && *lines[*i])
	{
		tmp = map;
		map = ft_strjoin(map, lines[*i]);
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		*i += 1;
	}
	sp = ft_split(map, '\n');
	free(map);
	skip_lines(lines, i, 0);
	if (lines[*i])
		ft_exit("parse error", 1);
	return (sp);
}

int	are_textures_and_colors_set(t_game *game, int got_colors)
{
	return ((!game->textures.east || !game->textures.north
			|| !game->textures.south || !game->textures.west
			|| !game->textures.door || got_colors != 2));
}

void	t_game_fill(t_game *game)
{
	int		i;
	int		got_colors;
	char	**splitted;
	int		j;

	i = 0;
	got_colors = 0;
	splitted = 0;
	while (game->file_lines[i] && are_textures_and_colors_set(game, got_colors))
	{
		if (*(game->file_lines[i++]))
		{
			splitted = ft_split(game->file_lines[i - 1], ' ');
			j = 0;
			while (splitted[j])
				j++;
			if (j != 2)
				ft_exit("Parse error", 1);
			add_item(splitted, game, &got_colors);
			free_double_ptr((void **)splitted);
		}
	}
	if (are_textures_and_colors_set(game, got_colors))
		ft_exit("Parse error", 1);
	game->map = fill_map(game->file_lines, &i);
}

t_game	*parser(int ac, char *av[])
{
	t_game	*game;

	check_arguments(ac, av);
	game = ft_calloc(1, sizeof(t_game));
	game->file_lines = readfile(av[1]);
	if (game->file_lines == 0)
		ft_exit("empty file", 1);
	t_game_fill(game);
	if (!check_map(game->map))
		ft_exit("Parse error", 1);
	return (game);
}
