/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:10 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/09/12 23:45:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		index_of(char *str, char c);
int		rgba_color(int r, int g, int b, int a);
void	ft_exit(char *msg, int err);
char	**readfile(char *filename);
void	free_double_ptr(void **ptr);
char	**split(char *str, char *dels);
int		get_color_from_string(char *color);
#endif
