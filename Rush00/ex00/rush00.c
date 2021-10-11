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

void	print_vertical_bound(int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	print_horizontal_bound(int i, int y)
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

	if (x < 1 || y < 1)
		return ;
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			if (i == 1 || i == y)
				print_vertical_bound(j, x);
			else if (j == 1 || j == x)
				print_horizontal_bound(i, y);
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
