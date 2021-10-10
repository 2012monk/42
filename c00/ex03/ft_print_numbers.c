/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:21:50 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 11:21:52 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int	i;
	char arr[10];

	i = 0;
	while (i < 10)
	{
		ft_put_char('0' + i++);
	}
	write(1, arr, 10);
}

int main(int argc, char const *argv[])
{
	ft_print_numbers();
	return 0;
}
