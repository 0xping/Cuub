/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:45:51 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 23:46:37 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	skip_lines(char **lines, int *i, int should_exit)
{
	char	*trimmed;

	while (lines[*i])
	{
		trimmed = ft_strtrim(lines[*i], " ");
		if (*trimmed)
		{
			free(trimmed);
			if (should_exit)
				ft_exit("parse error", 1);
			break ;
		}
		free(trimmed);
		*i += 1;
	}
}
