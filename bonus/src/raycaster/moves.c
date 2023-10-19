/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:37:58 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/19 06:10:09 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_move_left_or_right(t_data *data, int direction);
void	ft_move_backward_or_forward(t_data *data, int direction);
void	ft_open_close_door(t_data *data);
void	ft_rotate(t_data *data);

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
	if (keycode == KEY_E)
		ft_open_close_door(data);
	return (0);
}

int	check_next_move(char **map, t_point player_point, int width, int height)
{
	int		i;
	int		j;
	bool	is_valid;

	i = player_point.y;
	j = player_point.x;
	is_valid = (i < width && j < width && i && map[(i + 1) / CELL_SIZE] && j);
	is_valid = (is_valid && map[i / CELL_SIZE][(j + 1) / CELL_SIZE]
			&& ft_strchr("03", map[i / CELL_SIZE][j / CELL_SIZE]));
	is_valid = (is_valid && ft_strchr("03", map[(i + 1) / CELL_SIZE][j
			/ CELL_SIZE]) && ft_strchr("03", map[(i - 1) / CELL_SIZE][j
			/ CELL_SIZE]));
	is_valid = (is_valid && ft_strchr("03", map[i / CELL_SIZE][(j + 1)
			/ CELL_SIZE]) && ft_strchr("03", map[i / CELL_SIZE][(j - 1)
			/ CELL_SIZE]));
	printf("2 = %d\n", is_valid);
	return (is_valid);
}

void	ft_move_left_or_right(t_data *data, int direction)
{
	double	x;
	double	y;
	double	tmp;

	x = data->player_point.x;
	tmp = x;
	y = data->player_point.y;
	x += round(cos(data->player_angle + PI / 2 * direction) * SPEED);
	if (check_next_move(data->map, (t_point){x, y}, data->map_width,
			data->map_height))
		data->player_point.x = x;
	y -= round(sin(data->player_angle + PI / 2 * direction) * SPEED);
	if (check_next_move(data->map, (t_point){tmp, y}, data->map_width,
			data->map_height))
		data->player_point.y = y;
	if (check_next_move(data->map, (t_point){x, y}, data->map_width,
			data->map_height))
		data->player_point.y = y;
	ft_rotate(data);
}

void	ft_move_backward_or_forward(t_data *data, int direction)
{
	double	x;
	double	y;
	double	tmp;

	x = data->player_point.x;
	tmp = x;
	y = data->player_point.y;
	x += round(cos(data->player_angle) * SPEED * direction);
	if (check_next_move(data->map, (t_point){x, y}, data->map_width,
			data->map_height))
		data->player_point.x = x;
	y -= round(sin(data->player_angle) * SPEED * direction);
	if (check_next_move(data->map, (t_point){tmp, y}, data->map_width,
			data->map_height))
		data->player_point.y = y;
	if (check_next_move(data->map, (t_point){x, y}, data->map_width,
			data->map_height))
		data->player_point.y = y;
	ft_rotate(data);
}
