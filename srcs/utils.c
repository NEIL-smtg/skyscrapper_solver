/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:34:32 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 01:28:11 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	valid_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
			return (0);
		while (av[i] && av[i] == '+')
			++i;
		while (av[i] && av[i] >= '0' && av[i] <= '9')
			++i;
		if (av[i] && !ft_isspace(av[i]))
			return (0);
		while (av[i] && ft_isspace(av[i]))
			++i;
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i] == '+')
		++i;
	while (s[i] >= '0' && s[i] <= '9')
		total = total * 10 + s[i++] - '0';
	return (total);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	error_msg(char *s)
{
	write(2, s, ft_strlen(s));
	return (1);
}
