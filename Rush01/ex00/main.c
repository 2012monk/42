/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:03:26 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 03:03:28 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

int	g_grid[9][9];
int	g_size;
int	g_row_condition[9][2];
int	g_col_condition[9][2];
int	g_row_candidates[9];
int	g_col_candidates[9];

void	setup_input(int size, char const **arr)
{
	int	i;

	g_size = size / 4;
	i = -1;
	while (++i < size)
	{
		if (i < g_size)
			g_col_condition[i % g_size][0] = arr[i][0] - '0';
		else if (i < g_size * 2)
			g_col_condition[i % g_size][1] = arr[i][0] - '0';
		else if (i < g_size * 3)
			g_row_condition[i % g_size][0] = arr[i][0] - '0';
		else
			g_row_condition[i % g_size][1] = arr[i][0] - '0';
	}
}

void	init_var(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		g_row_candidates[i] = 0;
		g_col_candidates[i] = 0;
		j = -1;
		while (++j < g_size)
			g_grid[i][j] = 0;
	}
}

int	main(int argc, char const **argv)
{
	setup_input(argc - 1, argv + 1);
	if (solve())
		print_board(g_grid, g_size);
	else
		print_str("Error\n");
	return (0);
}
