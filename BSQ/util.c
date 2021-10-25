/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:06:59 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 22:07:05 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a);
}

void	print_board(t_board *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		write(1, map->board[i], map->width);
		write(1, "\n", 1);
	}
}

void	throw_err(void)
{
	write(2, "map error\n", 11);
}
