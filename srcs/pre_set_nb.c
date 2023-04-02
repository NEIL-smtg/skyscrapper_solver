/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_set_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:49:04 by suchua            #+#    #+#             */
/*   Updated: 2023/04/02 23:13:08 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// if 1 is oposite of n or vice versa
int		simplest_order(int con1, int con2, int n)
{
	return ((con1 == 1 && con2 == n) || (con1 == n && con2 == 1));
}

void	set_simplest_col(t_info *info, int i)
{
	int	j;

	j = -1;
	while (info->con_up[i] == 1 && ++j < info->n)
		info->grid[j][i] = j + 1;
	while (info->con_down[i] == 1 && ++j < info->n)
		info->grid[j][i] = info->n - j;
}

void	set_simplest_row(t_info *info, int i)
{
	int	j;

	j = -1;
	while (info->con_left[i] == 1 && ++j < info->n)
		info->grid[i][j] = j + 1;
	while (info->con_right[i] == 1 && ++j < info->n)
		info->grid[i][j] = info->n - j;
}

void	set_single_simplest(t_info *info, int i)
{
	if (info->con_up[i] == 1)
		info->grid[0][i] = info->n;
	if (info->con_down[i] == 1)
		info->grid[info->n - 1][i] = info->n;
	if (info->con_left[i] == 1)
		info->grid[i][0] = info->n;
	if (info->con_right[i] == 1)
		info->grid[i][info->n - 1] = info->n;
	if (info->con_up[i] == info->n)
		info->grid[0][i] = 1;
	if (info->con_down[i] == info->n)
		info->grid[info->n - 1][i] = 1;
	if (info->con_left[i] == info->n)
		info->grid[i][0] = 1;
	if (info->con_right[i] == info->n)
		info->grid[i][info->n - 1] = 1;
}

void	pre_set_nb(t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->n)
	{
		if (simplest_order(info->con_up[i], info->con_down[i], info->n))
			set_simplest_col(info, i);
		if (simplest_order(info->con_left[i], info->con_right[i], info->n))
			set_simplest_row(info, i);
		set_single_simplest(info, i);
	}
}
