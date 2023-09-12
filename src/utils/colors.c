/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:23:47 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/13 00:17:44 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	get_color_from_string(char *color)
{
	char	**sp;
	int		i;
	int		result;

	sp = ft_split(color, ',');
	i = 0;
	while (sp[i])
		i++;
	if (i != 3)
		ft_exit("Parse error", 1);
	result = rgba_color(0, arg_to_int(sp[0]), arg_to_int(sp[1]), arg_to_int(sp[2]));
	return (free_double_ptr((void **)sp), result);
}

int	rgba_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
