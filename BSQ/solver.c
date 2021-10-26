/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:48:04 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 16:48:05 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	debug(t_board *map, int **bd)
{
	for (int i =0;i<map->height; i++){
		for (int j=0;j < map->width; j++){
			printf("%d", bd[i][j]);
		}
		printf("%s", "\n");
	}
	printf("%s", "\n");
}

void	init_board(t_board *out, int **board)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < out->height)
	{
		j = -1;
		while (++j < out->width)
		{
			if (out->board[i][j] == out->empty)
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
}

void	fill_board(int **board, t_board *map, int i, int j)
{
	int	x;
	int	y;
	int	biggest;

	biggest = board[i][j];
	x = i + 1;
	while (--x > i - biggest)
	{
		y = j + 1;
		while (--y > j - biggest)
			map->board[x][y] = map->fill;
	}
}

void	calc_map(t_board *map, int **bd)
{
	int	i;
	int	j;
	int	x;
	int	y;

	init_board(map, bd);
	i = 0;
	x = 0;
	y = 0;
	while (++i < map->height)
	{
		j = 0;
		while (++j < map->width)
		{
			if (bd[i][j] == 0)
				continue ;
			bd[i][j] += min(bd[i][j - 1], bd[i - 1][j], bd[i - 1][j - 1]);
			if (bd[x][y] < bd[i][j])
			{
				x = i;
				y = j;
			}
		}
	}
	// debug(map, bd);
	fill_board(bd, map, x, y);
}

void	solve(t_board *map)
{
	int	**board;
	int	i;

	board = (int **) malloc(sizeof(int *) * map->height);
	if (!board)
	{
		printf("%s", "memory alloc failed!\n");
		exit(1);
	}
	i = -1;
	while (++i < map->height)
	{
		board[i] = (int *) malloc(sizeof(int *) * map->width);
		if (!board[i])
			exit(1);
	}
	calc_map(map, board);
	// int ** 해제
	print_board(map);
}
