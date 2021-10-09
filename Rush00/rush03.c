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

void	rush(int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= h)
	{
		j = 0;
		while (++j <= w)
		{
			if (j == 1 && (i == 1 || i == h))
				ft_putchar('A');
			else if (j == w && (i == 1 || i == h))
				ft_putchar('C');
			else if (i > 1 && i < h && j > 1 && j < w)
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		ft_putchar('\n');
	}
}
