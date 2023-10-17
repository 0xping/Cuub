/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:01:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 21:45:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

typedef struct s_data
{
	char	**map;
	int		map_width;
	int		map_height;
	char	player_char;
	double	player_angle;
	t_point	player_point;
	t_point	a_point;
	t_point	v_point;
	int		ray_nb;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_data;

typedef enum directions
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
}			t_directions;

void		ft_rotate(t_data *data);
void		ft_window(t_data *data);
double		ft_find_player(t_data *data);
int			ft_key_press(int keycode, t_data *data);
void		ft_up(t_data *data);
void		ft_down(t_data *data);
int			ft_check_wall(t_data *data, int a);
int			ft_quit(t_data *vars);

#endif