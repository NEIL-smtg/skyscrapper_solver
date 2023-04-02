/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:30:20 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 20:40:06 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	used_before(int **grid, int row, int col, int num)
{
	int	i;

	i = -1;
	while (++i < col)
		if (grid[row][i] == num)
			return (1);
	i = -1;
	while (++i < row)
		if (grid[i][col] == num)
			return (1);
	return (0);
}

int	is_valid(t_info *info, int row, int col, int num)
{
	if (used_before(info->grid, row, col, num))
		return (0);
	if (!fulfill_con(info, row, col, num))
		return (0);
	return (1);
}

int	all_valid(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->n)
	{
		j = -1;
		while (++j < info->n)
			if (info->grid[i][j] == 0)
				return (1);
	}
	return (match_con(info));
}

int	solve(t_info *info, int row, int col)
{
	int	nrow;
	int	ncol;
	int	num;

	if (row == info->n)
		return (1);
	nrow = row;
	if (col == info->n - 1)
		nrow++;
	ncol = (col + 1) % info->n;
	if (info->grid[row][col])
		return (solve(info, nrow, ncol));
	num = 0;
	while (++num <= info->n)
	{
		if (is_valid(info, row, col, num))
		{
			info->grid[row][col] = num;
			if (solve(info, nrow, ncol) && all_valid(info))
				return (1);
			info->grid[row][col] = 0;
		}
	}
	return (0);
}
