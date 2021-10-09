/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:38:34 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/09 17:38:39 by seounlee         ###   ########.fr       */
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
			if ((i == 1 && j == 1)
				|| (i == h && j == w && w != 1 && h != 1))
				ft_putchar('/');
			else if ((i == 1 && j == w) || (i == h && j == 1))
				ft_putchar('\\');
			else if (i > 1 && i < h && j > 1 && j < w)
				ft_putchar(' ');
			else
				ft_putchar('*');
		}
		ft_putchar('\n');
	}
}
