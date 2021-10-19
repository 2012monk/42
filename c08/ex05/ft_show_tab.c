/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:01:15 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/19 15:01:16 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	ft_put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		ft_put_str(par->str);
		ft_put_str("\n");
		ft_putnbr(par->size);
		ft_put_str("\n");
		ft_put_str(par->copy);
		ft_put_str("\n");
		par++;
	}
}
