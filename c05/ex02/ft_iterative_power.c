/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:51:39 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 19:51:40 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;
	int	prev;

	if (power < 0)
		return (0);
	ret = 1;
	prev = nb;
	while (power)
	{
		if (power & 1)
			ret *= prev;
		prev *= prev;
		power /= 2;
	}
	return (ret);
}
