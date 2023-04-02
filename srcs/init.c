/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:31:28 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 17:20:28 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_size(char *s)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			++i;
		if (s[i] >= '0' && s[i] <= '9')
			++size;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			++i;
	}
	return (size);
}

int	valid_constr(char *s, int n)
{
	int	i;
	int	num;

	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			++i;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
		{
			num = ft_atoi(&s[i]);
			if (num > n || num <= 0)
				return (-1);
			++i;
		}
	}
	return (1);
}

void	init_constraints(int *con, char *s, int start, int end)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			++i;
		if (s[i] >= '0' && s[i] <= '9')
			++size;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
		{
			if (size > start && size <= end)
				con[j++] = ft_atoi(&s[i]);
			++i;
		}
	}
}

int	init_grid(t_info *info)
{
	int	i;
	int	j;

	info->grid = malloc(sizeof(int *) * (info->size / 4));
	if (!info->grid)
		return (-1);
	i = -1;
	while (++i < info->size / 4)
	{
		info->grid[i] = malloc(sizeof(int) * (info->size / 4));
		if (!info->grid[i])
			return (-1);
		j = -1;
		while (++j < info->size / 4)
			info->grid[i][j] = 0;
	}
	return (1);
}

int	init(t_info *info, char *s)
{
	info->size = get_size(s);
	if (info->size % 4 != 0 || valid_constr(s, info->size / 4) == -1)
		return (-1);
	info->con_down = malloc(sizeof(int) * (info->size / 4));
	info->con_left = malloc(sizeof(int) * (info->size / 4));
	info->con_right = malloc(sizeof(int) * (info->size / 4));
	info->con_up = malloc(sizeof(int) * (info->size / 4));
	if (!info->con_down || !info->con_left || !info->con_right || !info->con_up)
		return (-1);
	info->n = info->size / 4;
	init_constraints(info->con_up, s, 0, info->n);
	init_constraints(info->con_down, s, info->n, info->n * 2);
	init_constraints(info->con_left, s, info->n * 2, info->n * 3);
	init_constraints(info->con_right, s, info->n * 3, info->n * 4);
	return (1);
}
