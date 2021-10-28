/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojoo <sojoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:25:25 by sojoo             #+#    #+#             */
/*   Updated: 2021/10/27 12:28:19 by sojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	ft_atoi_ht(char *buf, int i)
{
	int	result;
	int	j;

	result = 0;
	j = 0;
	while (j < i)
	{
		if (buf[j] < 48 || buf[j] > 57)
			return (0);
		result = (result * 10) + (buf[j] - '0');
		j++;
	}
	return (result);
}

int	redun_check(t_board *board_info)
{
	if (board_info -> fill == board_info -> obstacle)
		return (0);
	if (board_info -> fill == board_info -> empty)
		return (0);
	if (board_info -> obstacle == board_info -> empty)
		return (0);
	return (1);
}

int	width_height(char *buf, t_board *board_info, int i, int j)
{
	int	ht;
	int	wt;

	ht = ft_atoi_ht(buf, i);
	if (ht <= 0)
		return (0);
	board_info -> height = ht;
	wt = 0;
	while (buf[j] && buf[j] != '\n')
	{
		wt++;
		j++;
	}
	board_info -> width = wt;
	if (redun_check(board_info) == 0)
		return (0);
	return (1);
}

int	first_line(char *buf, t_board *board_info)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (buf[i] < 32 || buf[i] > 126)
			return (0);
		i++;
	}
	if (i < 4)
		return (0);
	j = i + 1;
	board_info -> fill = buf[--i];
	board_info -> obstacle = buf[--i];
	board_info -> empty = buf[--i];
	if (width_height(buf, board_info, i, j) == 0)
		return (0);
	return (1);
}
