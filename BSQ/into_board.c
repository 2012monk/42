/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:28:31 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/27 12:45:33 by sojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	into_board(char *buf, t_board *board_info, int idx, int i)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (board_info -> width + 1));
	if (!line)
		return (0);
	i = 0;
	while (*buf != '\n')
	{
		if (*buf == board_info -> obstacle || *buf == board_info -> empty)
			line[i++] = *buf;
		else
		{
			free(line);
			return (-1);
		}
		buf++;
	}
	if (i != board_info -> width)
	{
		free(line);
		return (-1);
	}
	line[i] = '\0';
	board_info -> board[idx] = line;
	return (1);
}

int	into_board_check(char *buf, t_board *board_info, int idx)
{
	int	i;

	while (*buf != '\n')
		buf++;
	idx = 0;
	buf++;
	while (*buf != '\0')
	{
		i = into_board(buf, board_info, idx++, 0);
		if (board_info->height < idx || i == -1 || i == 0)
		{
			board_info->board[idx - 1] = 0;
			if (board_info->height <= idx || i == -1)
				return (-1);
			return (0);
		}
		buf = buf + board_info -> width + 1;
	}
	board_info -> board[idx] = 0;
	if (idx != board_info -> height)
		return (-1);
	return (1);
}
