/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:36:47 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 22:05:31 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_horizontal_down(t_data *data)
{
	double	tmp;
	double	tmp2;

	data->a_point.y = (floor(data->player_point.y / CELL_SIZE) * CELL_SIZE)
		+ CELL_SIZE;
	data->a_point.x = data->player_point.x + (((data->player_point.y
					- data->a_point.y)) / tan(data->player_angle));
	if (data->a_point.x >= data->map_width || data->a_point.x <= 0)
	{
		data->a_point = (t_point){data->map_width, data->map_height};
		return ;
	}
	if (ft_check_wall(data, 1))
		return ;
	tmp2 = data->a_point.y;
	tmp = data->a_point.x;
	data->a_point.y += CELL_SIZE;
	data->a_point.x += ((tmp2 - data->a_point.y) / tan(data->player_angle));
	tmp = data->a_point.x - tmp;
	while (data->a_point.x > 0 && data->a_point.x < data->map_width
		&& !ft_check_wall(data, 1))
	{
		data->a_point.y += CELL_SIZE;
		data->a_point.x += tmp;
	}
}

void	ft_down_right(t_data *data)
{
	double	tmp;
	double	tmp2;

	data->v_point.x = (floor(data->player_point.x / CELL_SIZE) * CELL_SIZE)
		+ CELL_SIZE + 0.00001;
	data->v_point.y = data->player_point.y - (data->v_point.x
			- data->player_point.x) * tan(data->player_angle);
	if (data->v_point.y >= data->map_height || data->v_point.y <= 0)
	{
		data->v_point = (t_point){data->map_width, data->map_height};
		return ;
	}
	if (ft_check_wall(data, 0))
		return ;
	tmp = data->v_point.x;
	data->v_point.x += CELL_SIZE;
	tmp2 = ((data->v_point.x - tmp) * (tan(data->player_angle)));
	data->v_point.y = data->v_point.y - ((data->v_point.x - tmp)
			* (tan(data->player_angle)));
	while (data->v_point.y < data->map_height && data->v_point.y > 0
		&& !ft_check_wall(data, 0))
	{
		data->v_point.x += CELL_SIZE;
		data->v_point.y -= tmp2;
	}
}

void	ft_down_left(t_data *data)
{
	double	tmp;
	double	tmp2;

	data->v_point.x = floor(data->player_point.x / CELL_SIZE) * CELL_SIZE
		- 0.00001;
	data->v_point.y = data->player_point.y - (data->v_point.x
			- data->player_point.x) * tan(data->player_angle);
	if (data->v_point.y >= data->map_height || data->v_point.y <= 0)
	{
		data->v_point = (t_point){data->map_width, data->map_height};
		return ;
	}
	if (ft_check_wall(data, 0))
		return ;
	tmp = data->v_point.x;
	data->v_point.x -= CELL_SIZE;
	tmp2 = ((data->v_point.x - tmp) * (tan(data->player_angle)));
	data->v_point.y = data->v_point.y - ((data->v_point.x - tmp)
			* (tan(data->player_angle)));
	while (data->v_point.y < data->map_height && data->v_point.y > 0
		&& !ft_check_wall(data, 0))
	{
		data->v_point.x -= CELL_SIZE;
		data->v_point.y -= tmp2;
	}
}

void	ft_down(t_data *data)
{
	if (cos(data->player_angle) >= 0)
		ft_down_right(data);
	else if (cos(data->player_angle) < 0)
		ft_down_left(data);
	ft_horizontal_down(data);
}
