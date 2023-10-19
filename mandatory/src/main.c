/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:55:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/19 07:17:07 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"


int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->game_config = parser(ac, av);
	data->map = data->game_config->map;
	data->player_angle = ft_find_player(data);
	ft_window(data);
}
