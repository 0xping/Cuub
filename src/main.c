/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:55:37 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 22:56:03 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inc.h"

void	print(t_game *game)
{
	int	i;

	printf("ceil  :  %d\n", game->ceil_color);
	printf("floor :  %d\n", game->floor_color);
	printf("east  :  %s\n", game->textures.east);
	printf("west  :  %s\n", game->textures.west);
	printf("north :  %s\n", game->textures.north);
	printf("south :  %s\n", game->textures.south);
	printf("\n\n map :\n");
	i = 0;
	while (game->map[i])
		printf("%s\n", game->map[i++]);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	game = parser(ac, av);
	print(game);
	return (exit(0), 0);
}
