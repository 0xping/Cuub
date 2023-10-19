/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:09:15 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 23:00:25 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static size_t	count_chunks(char *cmd, char *dels)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (cmd[i])
	{
		if (ft_strchr(dels, cmd[i]))
			result++;
		i++;
	}
	return (result + 1);
}

static void	fill_arr_handel_empty(size_t words, char *s, char *dels,
		char ***result)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		if (i == 0 && ft_strchr(dels, s[0]))
			(*result)[i] = ft_strdup("");
		else
		{
			if (s[start] && ft_strchr(dels, s[start]))
				start++;
			end = start;
			while (s[end] && !ft_strchr(dels, s[end]))
				end++;
			(*result)[i] = ft_substr(s, start, end - start);
			start = end;
		}
		i++;
	}
}

char	**split(char *str, char *dels)
{
	char	**result;
	size_t	slices;

	if (!str)
		return (0);
	slices = count_chunks(str, dels);
	result = ft_calloc(slices + 1, sizeof(char *));
	if (result)
	{
		fill_arr_handel_empty(slices, str, dels, &result);
	}
	return (result);
}
