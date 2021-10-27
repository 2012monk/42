/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:36:08 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/27 12:55:18 by sojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	transfer_file(char *argv, t_board *board_info, int i)
{
	char	*buf;

	buf = read_map_file(argv);
	if (!buf)
		return (-1);
	if (first_line(buf, board_info) == 0)
	{
		free(buf);
		return (-1);
	}
	board_info -> board = (char **)malloc(sizeof(char *) * \
			(board_info -> height + 1));
	if (!board_info -> board)
	{
		free(buf);
		return (0);
	}
	i = into_board_check(buf, board_info, 0);
	if (i == -1 || i == 0)
	{
		free(buf);
		return (i);
	}
	free(buf);
	return (1);
}

int	transfer_file_stdin(char *buf, t_board *board_info, int i)
{
	if (!buf)
		return (-1);
	if (first_line(buf, board_info) == 0)
	{
		free(buf);
		return (-1);
	}
	board_info -> board = (char **)malloc(sizeof(char *) * \
			(board_info -> height + 1));
	if (!board_info -> board)
	{
		free(buf);
		return (0);
	}
	i = into_board_check(buf, board_info, 0);
	if (i == -1 || i == 0)
	{
		free(buf);
		return (i);
	}
	free(buf);
	return (1);
}
