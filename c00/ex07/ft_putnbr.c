/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:24:25 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 11:24:26 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	tmp[10];
	char	sign_char;
	int		sign;
	int		i;

	i = 9;
	tmp[i] = '0';
	sign = 1;
	if (n < 0)
	{
		sign_char = '-';
		sign = -1;
	}
	while (n != 0)
	{
		tmp[i] = '0' + (n % 10) * sign;
		n /= 10;
		i--;
	}
	write(1, &sign_char, 1);
	write(1, &tmp[i], 10 - i);
}
