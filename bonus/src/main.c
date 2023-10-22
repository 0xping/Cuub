/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:55:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 17:48:16 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

void	ft_draw_line(t_data *data, t_point end, int vertical,
			t_directions direction);
t_img	*get_texture_data(void *mlx_ptr, char *texture);
int		ft_compare(t_data *data);
int		ft_mouse_move(int x, int y, t_data *data);
void	ft_minimap(t_data *data);

void	load_textures(t_data *data)
{
	data->textures[0] = get_texture_data(data->mlx_ptr,
			data->game_config->textures.north);
	data->textures[1] = get_texture_data(data->mlx_ptr,
			data->game_config->textures.south);
	data->textures[2] = get_texture_data(data->mlx_ptr,
			data->game_config->textures.west);
	data->textures[3] = get_texture_data(data->mlx_ptr,
			data->game_config->textures.east);
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
	ft_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
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
	data->last_mouse_x = WIDTH / 2;
	ft_rotate(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win_ptr, 17, 0, ft_quit, data);
	mlx_hook(data->win_ptr, 6, 1L << 6, ft_mouse_move, data);
	mlx_loop(data->mlx_ptr);
}

void	ft_work_(t_data *data)
{
	t_directions	direction;
	t_point			end;
	int				vertical;

	vertical = 0;
	data->door = 0;
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
		vertical = 1;
		(cos(data->player_angle) >= 0) && (direction = EAST);
		(cos(data->player_angle) < 0) && (direction = WEST);
		end = (t_point){data->v_point.x, data->v_point.y};
	}
	ft_draw_line(data, end, vertical, direction);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->game_config = parser(ac, av);
	data->map = data->game_config->map;
	data->player_angle = ft_find_player(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HIGH, "cub3d");
	data->img.img = mlx_new_image(data->mlx_ptr, WIDTH, HIGH);
	load_textures(data);
	ft_window(data);
}
