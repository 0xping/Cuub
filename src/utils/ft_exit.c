/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:36:52 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 23:57:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_exit(char *msg, int err)
{
	ft_putstr_fd(COLOR_RED" Error\n    ", 2);
	ft_putendl_fd(msg, 2);
	exit(err);
}
