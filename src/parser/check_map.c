/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:52:50 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 21:49:44 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

size_t	get_max_line_len(char **map)
{
	size_t	max;
	int		i;

	max = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	make_map_rectangle(char **map)
{
	size_t	max_len;
	int		i;
	char	*tmp;

	max_len = get_max_line_len(map);
	i = 0;
	while (map[i])
	{
		while (ft_strlen(map[i]) < max_len)
		{
			tmp = map[i];
			map[i] = ft_strjoin(map[i], " ");
			free(tmp);
		}
		i++;
	}
}

void	check_surrounds(bool *valid, char **map, int i, int j)
{
	*valid = (*valid && i && map[i + 1] && j && map[i][j + 1] && map[i][j + 1]);
	*valid = (*valid && ft_strchr("NEWS10", map[i + 1][j])
			&& ft_strchr("NEWS10", map[i - 1][j]));
	*valid = (*valid && ft_strchr("NEWS10", map[i][j + 1])
			&& ft_strchr("NEWS10", map[i][j - 1]));
}
// *valid = (*valid && ft_strchr("NEWS10", map[i + 1][j + 1])
// 		&& ft_strchr("NEWS10", map[i - 1][j - 1]));
// *valid = (*valid && ft_strchr("NEWS10", map[i - 1][j - 1])
// 		&& ft_strchr("NEWS10", map[i + 1][j + 1]));

bool	check_map(char **map)
{
	bool	is_valid;
	int		players;
	size_t	i;
	size_t	j;

	make_map_rectangle(map);
	is_valid = 1;
	players = 0;
	i = 0;
	while (map[i] && is_valid)
	{
		j = 0;
		while (map[i][j] && is_valid)
		{
			players += !!ft_strchr("NEWS", map[i][j]);
			if (ft_strchr("NEWS0", map[i][j]))
				check_surrounds(&is_valid, map, i, j);
			else
				is_valid = !!ft_strchr("1 ", map[i][j]);
			j++;
		}
		i++;
	}
	return (is_valid && players == 1);
}
