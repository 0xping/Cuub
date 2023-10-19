/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:35:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 22:07:33 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_horizontal_up(t_data *data)
{
	double	a_x_increment;
	double	angle_tangent;

	a_x_increment = CELL_SIZE / tan(data->player_angle);
	angle_tangent = tan(data->player_angle);
	data->a_point.y = floor(data->player_point.y / CELL_SIZE) * CELL_SIZE
		- 0.00001;
	data->a_point.x = data->player_point.x + (data->player_point.y
			- data->a_point.y) / angle_tangent;
	if (data->a_point.x >= data->map_width || data->a_point.x <= 0)
	{
		data->a_point.x = data->map_width;
		data->a_point.y = data->map_height;
		return ;
	}
	while (!ft_check_wall(data, 1))
	{
		data->a_point.y -= CELL_SIZE;
		data->a_point.x += a_x_increment;
		if (data->a_point.x < 0 || data->a_point.x >= data->map_width)
			return ;
	}
}

void	ft_up_right(t_data *data)
{
	double	v_x_increment;
	double	angle_tangent;
	double	tmp_x;
	double	tmp_y;

	v_x_increment = CELL_SIZE;
	angle_tangent = tan(data->player_angle);
	data->v_point.x = (floor(data->player_point.x / CELL_SIZE) * CELL_SIZE)
		+ CELL_SIZE;
	data->v_point.y = data->player_point.y - (data->v_point.x
			- data->player_point.x) * angle_tangent;
	if (data->v_point.y >= data->map_height || data->v_point.y <= 0)
	{
		data->v_point = (t_point){data->map_width, data->map_height};
		return ;
	}
	while (!ft_check_wall(data, 0))
	{
		tmp_x = data->v_point.x;
		data->v_point.x += v_x_increment;
		tmp_y = (data->v_point.x - tmp_x) * angle_tangent;
		data->v_point.y -= tmp_y;
		if (data->v_point.y >= data->map_height || data->v_point.y <= 0)
			return ;
	}
}

void	ft_up_left(t_data *data)
{
	double	tmp;
	double	tmp2;

	data->v_point.x = floor(data->player_point.x / CELL_SIZE) * CELL_SIZE
		- 0.00001;
	data->v_point.y = data->player_point.y - ((data->v_point.x
				- data->player_point.x) * tan(data->player_angle));
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

void	ft_up(t_data *data)
{
	if (cos(data->player_angle) >= 0)
		ft_up_right(data);
	else if (cos(data->player_angle) < 0)
		ft_up_left(data);
	ft_horizontal_up(data);
}
