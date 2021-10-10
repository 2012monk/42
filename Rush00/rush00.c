/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:41:32 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 23:37:46 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	process_vertical(int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	process_horizontal(int i, int y)
{
	if (i == 1 || i == y)
		ft_putchar('o');
	else
		ft_putchar('|');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || y < 0)
		return ;
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			if (i == 1 || i == y)
				process_vertical(j, x);
			else if (j == 1 || j == x)
				process_horizontal(i,y);
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
