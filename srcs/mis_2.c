/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:18:05 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:08:05 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	w_error(char *file, char *fcmd)
{
	char *p;

	if (fcmd)
		free(fcmd);
	p = ft_strdup("\0");
	p = ft_strjoinf(p, "minishell: ");
	p = ft_strjoinf(p, "command not found:");
	p = ft_strjoinf(p, file);
	free(file);
	ft_putendl_fd(p, 2);
	free(p);
}

void	trim_split(char **av)
{
	int		x;
	char	*tmp;

	x = 0;
	while (av[x] != 0)
	{
		tmp = av[x];
		av[x] = ft_strtrim(av[x]);
		free(tmp);
		x++;
	}
}

void	w_errornf(char *str)
{
	char	*error;

	error = ft_strdup("\0");
	error = ft_strjoinf(error,
	"minishell: command not found / permission denied: ");
	error = ft_strjoinf(error, str);
	ft_putendl_fd(error, 2);
	free(error);
}
