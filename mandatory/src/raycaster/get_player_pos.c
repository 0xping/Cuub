/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:21:01 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 16:46:52 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

double	get_angle(char player_char)
{
	if (player_char == 'E')
		return (0);
	else if (player_char == 'N')
		return (PI / 2);
	else if (player_char == 'W')
		return (PI);
	else if (player_char == 'S')
		return (3 * PI / 2);
	return (0);
}

double	ft_find_player(t_data *data)
{
	int		i;
	int		j;
	char	player_char;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NEWS", data->map[i][j]))
			{
				data->player_point.x = j * CELL_SIZE + CELL_SIZE / 2;
				data->player_point.y = i * CELL_SIZE + CELL_SIZE / 2;
				player_char = data->map[i][j];
				data->map[i][j] = '0';
				return (get_angle(player_char));
			}
			j++;
		}
		i++;
	}
	return (0);
}
