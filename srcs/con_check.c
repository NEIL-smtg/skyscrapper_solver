/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:20:38 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 20:55:48 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	visible_up(t_info *info)
{
	int	i;
	int	j;
	int	max;
	int	seen;

	i = -1;
	while (++i < info->n)
	{
		j = -1;
		seen = 0;
		max = 0;
		while (++j < info->n)
		{
			if (info->grid[j][i] > max)
			{
				max = info->grid[j][i];
				++seen;
			}
		}
		if (seen != info->con_up[i])
			return (0);
	}
	return (1);
}

int	visible_down(t_info *info)
{
	int	i;
	int	j;
	int	max;
	int	seen;

	i = -1;
	while (++i < info->n)
	{
		j = info->n;
		seen = 0;
		max = 0;
		while (--j >= 0)
		{
			if (info->grid[j][i] > max)
			{
				max = info->grid[j][i];
				++seen;
			}
		}
		if (seen != info->con_down[i])
			return (0);
	}
	return (1);
}

int	visible_left(t_info *info)
{
	int	i;
	int	j;
	int	max;
	int	seen;

	i = -1;
	while (++i < info->n)
	{
		j = -1;
		seen = 0;
		max = 0;
		while (++j < info->n)
		{
			if (info->grid[i][j] > max)
			{
				max = info->grid[i][j];
				++seen;
			}
		}
		if (seen != info->con_left[i])
			return (0);
	}
	return (1);
}

int	visible_right(t_info *info)
{
	int	i;
	int	j;
	int	max;
	int	seen;

	i = -1;
	while (++i < info->n)
	{
		j = info->n;
		seen = 0;
		max = 0;
		while (--j >= 0)
		{
			if (info->grid[i][j] > max)
			{
				max = info->grid[i][j];
				++seen;
			}
		}
		if (seen != info->con_right[i])
			return (0);
	}
	return (1);
}

int	match_con(t_info *info)
{
	if (!visible_up(info))
		return (0);
	if (!visible_down(info))
		return (0);
	if (!visible_left(info))
		return (0);
	if (!visible_right(info))
		return (0);
	return (1);
}
