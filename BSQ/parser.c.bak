/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:07:49 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 22:07:50 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_board	*parse_map(char *file)
{
	t_board	*board;
	char	**b;
	int		i;

	board = malloc(sizeof(t_board));
	b = get_lines(file);
	i = 0;
	while (b[0][i])
		i++;
	board->fill = b[0][i - 1];
	board->obstacle = b[0][i - 2];
	board->empty = b[0][i - 3];
	b[0][i - 3] = '\0';
	board->height = ft_atoi(b[0]);
	board->width = ft_strlen(b[1]);
	board->board = b + 1;
	return (board);
}
