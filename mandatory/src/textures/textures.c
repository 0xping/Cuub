/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:57:33 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/22 16:46:59 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

unsigned int	get_color(t_img *img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

t_img	*get_texture_data(void *mlx_ptr, char *path)
{
	t_img	*result;

	result = malloc(sizeof(t_img));
	result->img = mlx_xpm_file_to_image(mlx_ptr, path, &result->width,
			&result->height);
	if (!result->img)
		ft_exit("Error while getting textures", 1);
	result->addr = mlx_get_data_addr(result->img, &result->bits_per_pixel,
			&result->line_length, &result->endian);
	return (result);
}
