/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:12:04 by suchua            #+#    #+#             */
/*   Updated: 2023/04/02 22:58:42 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_info
{
	int	*con_left;
	int	*con_right;
	int	*con_up;
	int	*con_down;
	int	size;
	int	**grid;
	int	n;
}	t_info;

//isspace
int		ft_isspace(char c);

//check valid arg
int		valid_arg(char *av);

//init
int		init(t_info *info, char *s);
int		init_grid(t_info *info);

//convert alpha to int
int		ft_atoi(char *s);

//prompt error msg
int		error_msg(char *s);

//preset
void	pre_set_nb(t_info *info);

//solution
int		solve(t_info *info, int row, int col);
int		fulfill_con(t_info *info, int row, int col, int num);
int		match_con(t_info *info);

//print out the gird
void	print_grid(int **grid, int n);

#endif