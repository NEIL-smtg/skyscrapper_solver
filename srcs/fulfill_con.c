/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulfill_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:29:41 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 20:33:56 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	fulfill_con_up(t_info *info, int row, int col, int num)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	seen = 0;
	max = 0;
	while (i < row)
	{
		if (info->grid[i][col] > max)
		{
			max = info->grid[i][col];
			++seen;
		}
		++i;
	}
	if (num > max)
		++seen;
	if (seen > info->con_up[col])
		return (0);
	return (1);
}

int	fulfill_con_down(t_info *info, int row, int col, int num)
{
	int	i;
	int	max;
	int	seen;

	i = row + 1;
	max = 0;
	seen = 0;
	while (i < info->n)
	{
		if (info->grid[i][col] > max)
		{
			max = info->grid[i][col];
			++seen;
		}
		++i;
	}
	if (num > max)
		++seen;
	if (seen > info->con_down[col])
		return (0);
	return (1);
}

int	fulfill_con_left(t_info *info, int row, int col, int num)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	seen = 0;
	max = 0;
	while (i < col)
	{
		if (info->grid[row][i] > max)
		{
			max = info->grid[row][i];
			++seen;
		}
		++i;
	}
	if (num > max)
		++seen;
	if (seen > info->con_left[row])
		return (0);
	return (1);
}

int	fulfill_con_right(t_info *info, int row, int col, int num)
{
	int	i;
	int	max;
	int	seen;

	i = col + 1;
	max = 0;
	seen = 0;
	while (i < info->n)
	{
		if (info->grid[row][i] > max)
		{
			max = info->grid[row][i];
			++seen;
		}
		++i;
	}
	if (num > max)
		++seen;
	if (seen > info->con_right[row])
		return (0);
	return (1);
}

int	fulfill_con(t_info *info, int row, int col, int num)
{
	if (!fulfill_con_up(info, row, col, num))
		return (0);
	if (!fulfill_con_down(info, row, col, num))
		return (0);
	if (!fulfill_con_left(info, row, col, num))
		return (0);
	if (!fulfill_con_right(info, row, col, num))
		return (0);
	return (1);
}
