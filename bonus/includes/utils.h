/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:10 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 17:15:40 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

int			index_of(char *str, char c);
int			rgba_color(int r, int g, int b, int a);
void		ft_exit(char *msg, int err);
char		**readfile(char *filename);
void		free_double_ptr(void **ptr);
char		**split(char *str, char *dels);
int			get_color_from_string(char *color);
int			arg_to_int(const char *str);
void		my_mlx_pixel_put(t_img *image, int x, int y, int color);

#endif
