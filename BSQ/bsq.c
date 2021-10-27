/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:03:08 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 16:03:14 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_map(t_board *map)
{
	if (transfer_file_stdin(parse_stdin(), map, 0) == -1)
		throw_err();
	else
		solve(map);
	free_map(map);
}

void	solve_maps(int ac, char **av)
{
	int		i;
	t_board	*map;
	int		ret;

	map = (t_board *) malloc(sizeof(t_board));
	if (!map)
		return ;
	i = -1;
	while (++i < ac)
	{
		if (ac > 1 && i > 0)
			write(1, "\n", 1);
		ret = transfer_file(av[i], map, 0);
		if (ret == -1)
			throw_err();
		else if (ret == 0)
			break ;
		else
			solve(map);
		free_map(map);
	}
	if (ac == 0)
		solve_map(map);
	free(map);
}

int	main(int argc, char **argv)
{
	solve_maps(argc - 1, &argv[1]);
	system("leaks bsq");
}
