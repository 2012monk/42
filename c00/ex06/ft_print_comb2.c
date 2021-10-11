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

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			put_nbr(i);
			ft_putchar(' ');
			put_nbr(j);
			if (i == 98 && j == 99)
				return ;
			ft_putchar(',');
			ft_putchar(' ');
			j++;
		}
		i++;
	}
}
