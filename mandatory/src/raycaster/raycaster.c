/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:42:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 17:06:40 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	ft_quit(t_data *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	exit(0);
}

int	ft_get_x(t_point end, int is_vertical, int texture_width)
{
	int		flour;
	float	x;

	if (is_vertical)
	{
		flour = floor(end.y / CELL_SIZE) * CELL_SIZE;
		x = ((end.y - flour) * 100) / 100;
	}
	else
	{
		flour = floor(end.x / CELL_SIZE) * CELL_SIZE;
		x = ((end.x - flour) * 100) / 100;
	}
	x = (x / CELL_SIZE) * texture_width;
	return (x);
}

void	ft_draw_line(t_data *data, t_point end, int vertical,
		t_directions direction)
{
	int		color;
	int		i;
	int		distance_projection_plane;
	double	ray_distance;
	int		cub_size;
	double	x;
	double	wall_size;
	double	y;

	x = ft_get_x(end, vertical, data->textures[direction]->width);
	y = 0;
	i = 0;
	distance_projection_plane = (WIDTH / 2) / tan(PI / 6);
	ray_distance = sqrt(pow(end.x - data->player_point.x, 2) + pow(end.y
				- data->player_point.y, 2)) * cos(((PI / 6) - ((PI / 3) / WIDTH)
				* data->ray_nb));
	cub_size = (CELL_SIZE / ray_distance) * distance_projection_plane;
	wall_size = cub_size;
	if (cub_size > HIGH)
	{
		y = ((wall_size / 2 - (HIGH / 2)) / wall_size)
			* data->textures[direction]->height;
		cub_size = HIGH;
	}
	if (cub_size <= 0)
		cub_size = 0;
	while (i < HIGH)
	{
		if (i < (HIGH / 2) - (cub_size / 2))
			color = data->game_config->ceil_color;
		else if (i < (HIGH / 2) - (cub_size / 2) + cub_size)
		{
			if (y > data->textures[direction]->height)
				y = data->textures[direction]->height;
			color = get_color(data->textures[direction], x, y);
			y += data->textures[direction]->height / wall_size;
			if (y >= data->textures[direction]->height)
				y = data->textures[direction]->height;
		}
		else
			color = data->game_config->floor_color;
		my_mlx_pixel_put(&data->img, data->ray_nb, i, color);
		i++;
	}
}

int	ft_check_wall(t_data *data, int a)
{
	t_point	c;

	if (a)
		c = (t_point){data->a_point.x, data->a_point.y};
	else
		c = (t_point){data->v_point.x, data->v_point.y};
	if (c.x > 0 && c.y > 0 && c.y < data->map_height && c.x < data->map_width
		&& data->map[(int)(c.y / CELL_SIZE)][(int)(c.x / CELL_SIZE)] == '1')
		return (1);
	return (0);
}

int	ft_compare(t_data *data)
{
	double	h;
	double	v;

	if (data->a_point.x == data->map_width
		|| data->a_point.y == data->map_height || data->a_point.x == 0
		|| data->a_point.y == 0)
		return (0);
	else if (data->v_point.x == data->map_width
		|| data->v_point.y == data->map_height || data->v_point.x == 0
		|| data->v_point.y == 0)
		return (1);
	h = sqrt(pow(data->a_point.x - data->player_point.x, 2)
			+ pow(data->a_point.y - data->player_point.y, 2));
	v = sqrt(pow(data->v_point.x - data->player_point.x, 2)
			+ pow(data->v_point.y - data->player_point.y, 2));
	if (h < v && (data->player_angle))
		return (1);
	return (0);
}
