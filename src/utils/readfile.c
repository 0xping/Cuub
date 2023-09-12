/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:59:44 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 20:37:26 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	**readfile(char *filename)
{
	int		fd;
	char	*result;
	char	*line;
	char	**sp;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		exit(1);
	}
	result = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp = result;
		result = ft_strjoin(result, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	sp = split(result, "\n");
	return (free(result), sp);
}
