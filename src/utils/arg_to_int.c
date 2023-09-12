/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:14:59 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/13 00:17:18 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

int	arg_to_int(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		(void)((str[i] == '-') && (sign *= -1));
		i++;
	}
	(void)((str[i] == 0) && (ft_exit("parse error", 1), 1));
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if ((result > 2147483647 && sign == 1) || (result > 2147483648
				&& sign == -1))
			ft_exit("parse error", 1);
		i++;
	}
	(void)((str[i] != 0) && (ft_exit("parse error", 1), 1));
	return (result * sign);
}
