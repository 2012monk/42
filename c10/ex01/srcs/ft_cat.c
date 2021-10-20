/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:24:13 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 13:24:15 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		ft_echo();
	i = 0;
	while (++i < ac)
	{
		if (!av[i][0] || av[i][0] == '-')
			ft_echo();
		else if (do_print(av[i]) == -1)
			throw_err(av[0], av[i]);
	}
	return (0);
}
