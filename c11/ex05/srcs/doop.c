/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:19:08 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 22:19:10 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "doop.h"

int	is_valid_op(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '*')
		return (2);
	if (c == '/')
		return (3);
	if (c == '%')
		return (4);
	return (-1);
}

int	main(int ac, char **av)
{
	int	i;
	int	(*f[5])(int, int);
	int	a;
	int	b;

	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (ac != 4)
		return (1);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	i = is_valid_op(av[2][0]);
	if (i == -1)
		ft_putnbr(0);
	else if (i == 3 && b == 0)
		f_print(DIV_ERR);
	else if (i == 4 && b == 0)
		f_print(MOD_ERR);
	else
		ft_putnbr(f[i](a, b));
	write(1, "\n", 1);
	return (0);
}
