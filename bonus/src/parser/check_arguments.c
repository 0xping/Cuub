/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:04:21 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 23:04:43 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	check_arguments(int ac, char *av[])
{
	if (ac != 2)
		ft_exit(ERR_ARG_COUNT, 1);
	if (!ft_strrchr(av[1], '.') || ft_strcmp("cub", ft_strrchr(av[1], '.') + 1))
		ft_exit(ERR_FILE_EXT, 1);
}
