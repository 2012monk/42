/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:24:08 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 11:24:09 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int n)
{
	ft_putchar('0' + (n / 10));
	ft_putchar('0' + (n % 10));
}

void	put_delimiter(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	comb_recursive(int start, int n)
{
	if (n > 99)
		return ;
	put_nbr(start);
	ft_putchar(' ');
	put_nbr(n);
	if (!(start == 98 && n == 99))
		put_delimiter();
	comb_recursive(start, n + 1);
	if (start < 99 && n == 99)
		comb_recursive(start + 1, start + 2);
}

void	ft_print_comb2(void)
{
	comb_recursive(0, 1);
}
