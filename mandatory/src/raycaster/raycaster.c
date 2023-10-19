/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:42:27 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/19 07:08:36 by aait-lfd         ###   ########.fr       */
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

void	ft_draw_line(t_data *data, t_point from, t_point end, int direction)
{
	int		tmp;
	int		i;
	int		distance_projection_plane;
	double	ray_distance;
	int		cub_size;

	i = 0;
	distance_projection_plane = (WIDTH / 2) / tan(PI / 6);
	ray_distance = sqrt(pow(end.x - from.x, 2) + pow(end.y - from.y, 2))
		* cos(((PI / 6) - ((PI / 3) / WIDTH) * data->ray_nb));
	cub_size = (CELL_SIZE / ray_distance) * distance_projection_plane;
	if (cub_size > HIGH)
		cub_size = HIGH;
	if (cub_size < 0)
		cub_size = 0;

	while (i < (HIGH / 2) - (cub_size / 2))
	{
		my_mlx_pixel_put(&data->img, data->ray_nb, i, data->game_config->ceil_color); // ceiling
		i++;
	}
	tmp = i;
	while (i < tmp + cub_size)
	{
		// draw textures
		direction++;
		my_mlx_pixel_put(&data->img, data->ray_nb, i, 0xff0fdf);
		i++;
	}
	while (i < HIGH)
	{
		my_mlx_pixel_put(&data->img, data->ray_nb, i, data->game_config->floor_color); // floor
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
void	ft_work_(t_data *data)
{
	t_directions	direction;
	t_point			end;

	if (sin(data->player_angle) >= 0)
		ft_up(data);
	else
		ft_down(data);
	if (ft_compare(data) == 1)
	{
		(sin(data->player_angle) >= 0) && (direction = NORTH);
		(sin(data->player_angle) < 0) && (direction = SOUTH);
		end = (t_point){data->a_point.x, data->a_point.y};
	}
	else
	{
		(cos(data->player_angle) >= 0) && (direction = EAST);
		(cos(data->player_angle) < 0) && (direction = WEST);
		end = (t_point){data->v_point.x, data->v_point.y};
	}
	ft_draw_line(data, data->player_point, end, direction);
}

void	ft_window(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf("\033[0;31mError :\nmlx_init() failed\n");
		exit(1);
	}
	while (data->map[i])
		i++;
	data->map_height = i * CELL_SIZE;
	data->map_width = ft_strlen(data->map[0]) * CELL_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HIGH, "cub3d");
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HIGH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	ft_rotate(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win_ptr, 17, 0, ft_quit, data);
	mlx_loop(data->mlx_ptr);
}

void	ft_rotate(t_data *data)
{
	double	x;
	double	j;
	int		k;

	data->ray_nb = 0;
	x = data->player_angle;
	j = data->player_angle + 0.524;
	k = -1;
	while (++k < WIDTH)
	{
		data->player_angle = j;
		ft_work_(data);
		j = j - (PI / 3) / WIDTH;
		data->ray_nb++;
	}
	data->player_angle = x;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}
