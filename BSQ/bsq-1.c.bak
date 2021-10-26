/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:26:19 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/25 21:26:19 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_maps(int ac, char **av)
{
	int		i;
	t_board	*map;

	i = -1;
	while (++i < ac)
	{
		map = parse_map(av[i]);
		if (!map)
		{
			throw_err();
			continue ;
		}
		solve(map);
	}
}
/**
 * STDIN 처리 피요함
 * */

int	main(int ac, char **av)
{
	solve_maps(ac - 1, &av[1]);
	return (0);
}
