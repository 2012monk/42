/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:05:16 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 20:13:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int		is_printable(char c)
{
	return c != 127 && c > 32;
}

void	print_hex(int n){
	put_char('\\');
	if (n >= 16)
		put_char(n / 16 + 96);
	put_char(n % 16 + '0');
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
			put_char(*str);
		else
			print_hex(*str);
		str++;
	}
}

