/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:45:52 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 22:45:54 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	carry;
	int	digit;

	carry = n / 10;
	digit = n % 10;
	if (n < 0)
	{
		ft_putchar('-');
		carry = -carry;
		digit = -digit;
	}
	if (carry)
		ft_putnbr(carry);
	ft_putchar(digit + '0');
}
