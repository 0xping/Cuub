/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:13:31 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/02 18:18:08 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s1);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
int		ln_index(char *s);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
void	split_with_nl(char **s1, char **s2, char *s3);

#endif
