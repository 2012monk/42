/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:07:50 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/17 03:08:31 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "tower.h"

void	reverse_arr(int arr[], int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
		i++;
	}
}

void	copy_row(int board[][__MAX_SIZE__], int arr[], int x, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		arr[i] = board[x][i];
}

void	copy_col(int board[][__MAX_SIZE__], int arr[], int y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		arr[i] = board[i][y];
}

void	print_board(int board[][__MAX_SIZE__], int size)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			c = '0' + board[i][j] % 10;
			write(1, &c, 1);
			if (j != size - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}
