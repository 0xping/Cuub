/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:01:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 17:41:23 by aait-lfd         ###   ########.fr       */
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
	double	last_mouse_x;
	int		door;
	int		ray_nb;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*textures[4];
	t_game	*game_config;
	t_img	img;
}			t_data;

typedef enum directions
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3,
	DOOR = 4,
}			t_directions;

void			ft_rotate(t_data *data);
void			ft_window(t_data *data);
double			ft_find_player(t_data *data);
int				ft_key_press(int keycode, t_data *data);
void			ft_up(t_data *data);
void			ft_down(t_data *data);
int				ft_check_wall(t_data *data, int a);
int				ft_quit(t_data *vars);
unsigned int	get_color(t_img *img, int x, int y);
void			ft_work_(t_data *data);
#endif