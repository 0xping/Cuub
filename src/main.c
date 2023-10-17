/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:55:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/10/17 20:01:08 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_data	*data;

	game = parser(ac, av);
	data = malloc(sizeof(t_data));
	data->map = game->map;
	data->player_angle = ft_find_player(data);
	ft_window(data);
}
