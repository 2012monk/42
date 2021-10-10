/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:04:00 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 18:09:11 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int i;

	i = 0;
	while(i < size / 2 + ^(size & 1))
	{
		tmp = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = tmp;
		i++;
	}
}

