/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:41:32 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/09 17:41:33 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x < 1 || y < 1)
		return ;
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			if (j == 1 && (i == 1 || i == y))
				ft_putchar('A');
			else if (j == x && (i == 1 || i == y))
				ft_putchar('C');
			else if (i > 1 && i < y && j > 1 && j < x)
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		ft_putchar('\n');
	}
}
