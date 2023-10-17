/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:37:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 22:07:46 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_move_left_or_right(t_data *data, int direction);
void	ft_move_backward_or_forward(t_data *data, int direction);

int	ft_key_press(int keycode, t_data *data)
{
	int	direction;

	direction = 1;
	if (keycode == KEY_ESC)
		ft_quit(data);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		if (keycode == KEY_RIGHT)
			direction = -1;
		data->player_angle += 0.05 * direction;
		if (data->player_angle < 6.260000 * direction
			&& data->player_angle > 6.240000 * direction)
			data->player_angle = 0;
		ft_rotate(data);
	}
	if (keycode == KEY_W)
		ft_move_backward_or_forward(data, 1);
	if (keycode == KEY_S)
		ft_move_backward_or_forward(data, -1);
	if (keycode == KEY_A)
		ft_move_left_or_right(data, 1);
	if (keycode == KEY_D)
		ft_move_left_or_right(data, -1);
	return (0);
}

void	ft_move_left_or_right(t_data *data, int direction)
{
	int	x;
	int	y;

	x = data->player_point.x;
	y = data->player_point.y;
	x += round(cos(data->player_angle + PI / 2 * direction) * SPEED);
	if (data->map[y / CELL_SIZE][x / CELL_SIZE] == '1')
		return ;
	y -= round(sin(data->player_angle + PI / 2 * direction) * SPEED);
	if (data->map[y / CELL_SIZE][x / CELL_SIZE] == '1')
		return ;
	data->player_point.x = x;
	data->player_point.y = y;
	ft_rotate(data);
}

void	ft_move_backward_or_forward(t_data *data, int direction)
{
	int	x;
	int	y;

	x = data->player_point.x + round(cos(data->player_angle) * SPEED
			* direction);
	y = data->player_point.y;
	if (data->map[y / CELL_SIZE][x / CELL_SIZE] == '1')
		return ;
	y -= round(sin(data->player_angle) * SPEED * direction);
	if (data->map[y / CELL_SIZE][x / CELL_SIZE] == '1')
		return ;
	data->player_point = (t_point){x, y};
	ft_rotate(data);
}
