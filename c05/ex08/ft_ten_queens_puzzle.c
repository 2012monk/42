/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:54:30 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 20:54:31 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_visited[10][10];
int	g_horizontal[40];
int	g_diagonal_l[40];
int	g_diagonal_r[40];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_queens(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (g_visited[i][j])
				ft_putchar('0' + j);
		}
	}
	ft_putchar('\n');
}

int	rec(int x)
{
	int	i;
	int	ret;

	if (x == 10)
	{
		print_queens();
		return (1);
	}
	ret = 0;
	i = -1;
	while (++i < 10)
	{
		if (g_horizontal[i] || g_diagonal_l[x - i + 9] || g_diagonal_r[x + i])
			continue ;
		g_horizontal[i] = 1;
		g_diagonal_r[i + x] = 1;
		g_diagonal_l[x - i + 9] = 1;
		g_visited[x][i] = 1;
		ret += rec(x + 1);
		g_visited[x][i] = 0;
		g_horizontal[i] = 0;
		g_diagonal_r[i + x] = 0;
		g_diagonal_l[x - i + 9] = 0;
	}
	return (ret);
}

int	ft_ten_queens_puzzle(void)
{
	return (rec(0));
}
