/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:11:55 by suchua            #+#    #+#             */
/*   Updated: 2023/04/02 23:27:35 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_con(int *con, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%d ", con[i]);
	printf("\n");
}

void	free_everything(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n)
		free(info->grid[i]);
	free(info->grid);
	free(info->con_down);
	free(info->con_up);
	free(info->con_left);
	free(info->con_right);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2 || !valid_arg(av[1]))
		return (error_msg("invalid arguments\n"));
	if (init(&info, av[1]) == -1 || init_grid(&info) == -1)
		return (error_msg("invalid number of arguments / unable to malloc\n"));
	// pre_set_nb(&info);
	// print_grid(info.grid, info.n);
	if (solve(&info, 0, 0))
		print_grid(info.grid, info.n);
	else
		error_msg("No solution\n");
	free_everything(&info);
	return (0);
}
