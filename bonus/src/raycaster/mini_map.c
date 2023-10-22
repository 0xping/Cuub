/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:54:52 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 18:11:01 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 49;
	while (i < 51)
	{
		j = 74;
		while (j < 76)
		{
			my_mlx_pixel_put(&data->img, j, i, 0x00CC0000);
			j++;
		}
		i++;
	}
}

typedef struct s_mini_map_args
{
	t_data	*data;
	int		x;
	int		y;
	int		i;
	int		j;
}			t_mini_map_args;

void	render_minimap_pixels(t_mini_map_args args)
{
	if (args.x / 8 < 0 || args.x / 8 >= args.data->map_width / CELL_SIZE
		|| args.y / 8 < 0 || args.y / 8 >= args.data->map_height / CELL_SIZE
		|| args.data->map[args.y / 8][args.x / 8] == ' ')
		my_mlx_pixel_put(&args.data->img, args.j, args.i, 0x0000FFFF);
	else if (args.data->map[args.y / 8][args.x / 8] == '1')
		my_mlx_pixel_put(&args.data->img, args.j, args.i, 0x00000000);
	else if (args.data->map[args.y / 8][args.x / 8] == '0')
		my_mlx_pixel_put(&args.data->img, args.j, args.i, 0x00FFFFFF);
	else if (args.data->map[args.y / 8][args.x / 8] == '2')
		my_mlx_pixel_put(&args.data->img, args.j, args.i, 0x000000FF);
	else if (args.data->map[args.y / 8][args.x / 8] == '3')
		my_mlx_pixel_put(&args.data->img, args.j, args.i, 0x00009900);
}

void	ft_minimap(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = data->player_point.y / 8 - 50;
	while (i < 100)
	{
		x = data->player_point.x / 8 - 75;
		j = 0;
		while (j < 150)
		{
			render_minimap_pixels((t_mini_map_args){data, x, y, i, j});
			j++;
			x++;
		}
		i++;
		y++;
	}
	ft_draw_player(data);
}
