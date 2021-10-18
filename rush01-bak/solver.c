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

int	count_boxes(int tab[], int size)
{
	int	cnt;
	int	max;
	int	i;

	i = -1;
	max = 0;
	cnt = 0;
	while (++i < size)
	{
		if (tab[i] && tab[i] > max)
		{
			cnt++;
			max = tab[i];
		}
	}
	return (cnt);
}

int	check_line_constraints(int arr[], int left, int right, int size)
{
	int	ret;

	ret = count_boxes(arr, size) == left;
	reverse_arr(arr, size);
	return (ret && count_boxes(arr, size) == right);
}

int	is_valid_move(t_status *status, int val, int x, int y)
{
	int	col[__MAX_SIZE__];
	int	row[__MAX_SIZE__];
	int	col_pass;
	int	row_pass;

	copy_col(status->grid, col, y, status->size);
	copy_row(status->grid, row, x, status->size);
	col[x] = val;
	row[y] = val;
	col_pass = 1;
	row_pass = 1;
	if (x == status->size - 1)
		col_pass = check_line_constraints(col, status->col_constraints[y][LEFT],
				status->col_constraints[y][RIGHT], status->size);
	if (y == status->size - 1)
		row_pass = check_line_constraints(row, status->row_constraints[x][LEFT],
				status->row_constraints[x][RIGHT], status->size);
	return (col_pass && row_pass);
}

void	find_free_cell(int *x, int *y, int grid[][__MAX_SIZE__], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (grid[i][j] == 0)
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

int	solve(t_status *status)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	find_free_cell(&x, &y, status->grid, status->size);
	if (x == -1 || y == -1)
		return (1);
	while (++c <= status->size)
	{
		if (is_used_box(x, y, c, status) || !is_valid_move(status, c, x, y))
			continue ;
		place_box(x, y, c, status);
		if (solve(status))
			return (1);
		delete_box(x, y, c, status);
	}
	return (0);
}
