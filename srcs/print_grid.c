/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:38:58 by suchua            #+#    #+#             */
/*   Updated: 2023/03/28 17:04:31 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	print_grid(int **grid, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			ft_putnbr(grid[i][j]);
			ft_putchar(32);
		}
		ft_putchar('\n');
	}
}
