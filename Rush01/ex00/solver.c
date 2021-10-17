/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:06:34 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 03:06:36 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tower.h"

int	count_boxes(int tab[g_size])
{
	int	cnt;
	int	max;
	int	i;

	i = -1;
	max = 0;
	cnt = 0;
	while (++i < g_size)
	{
		if (tab[i] && tab[i] > max)
		{
			cnt++;
			max = tab[i];
		}
	}
	return (cnt);
}

int	check_line(int arr[], int left, int right)
{
	int	ret;

	ret = count_boxes(arr) == left;
	reverse_arr(arr, g_size);
	return (ret && count_boxes(arr) == right);
}

int	is_valid_move(int x, int y, int val)
{
	int	col[__MAX_SIZE__];
	int	row[__MAX_SIZE__];
	int	col_pass;
	int	row_pass;

	copy_col(g_grid, col, y, g_size);
	copy_row(g_grid, row, x, g_size);
	col[x] = val;
	row[y] = val;
	col_pass = 1;
	row_pass = 1;
	if (x == g_size - 1)
		col_pass = check_line(col,
				g_col_condition[y][0], g_col_condition[y][1]);
	if (y == g_size - 1)
		row_pass = check_line(row,
				g_row_condition[x][0], g_row_condition[x][1]);
	return (col_pass && row_pass);
}

void	find_free_cell(int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (g_grid[i][j] == 0)
			{
				*x = i;
				*y = j;
				return ;
			}
		}
	}
	*x = -1;
	*y = -1;
}

int	solve(void)
{
	int	x;
	int	y;
	int	c;
	int	bit;

	c = 0;
	find_free_cell(&x, &y);
	if (x == -1 || y == -1)
		return (1);
	while (++c <= g_size)
	{
		bit = 1 << c;
		if ((g_row_candidates[y] & bit) || (g_col_candidates[x] & bit)
			|| !is_valid_move(x, y, c))
			continue ;
		g_grid[x][y] = c;
		g_col_candidates[x] |= bit;
		g_row_candidates[y] |= bit;
		if (solve())
			return (1);
		g_grid[x][y] = 0;
		g_col_candidates[x] &= MASK ^ bit;
		g_row_candidates[y] &= MASK ^ bit;
	}
	return (0);
}
