/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:14:49 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 12:14:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(t_board *map)
{
	int	i;

	i = -1;
	if (!map->board)
		return ;
	while (map->board[++i])
	{
		free(map->board[i]);
		map->board[i] = NULL;
	}
	free(map->board);
	map->board = 0;
}

void	free_board(int **board, int height)
{
	int	i;

	if (!board)
		return ;
	i = -1;
	while (++i < height)
	{
		if (board[i])
			free(board[i]);
		board[i] = NULL;
	}
	free(board);
	board = NULL;
}

void	free_all(t_board *map)
{
	free_map(map);
	if (map)
		free(map);
}
