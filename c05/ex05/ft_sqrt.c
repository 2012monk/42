/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:18:27 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 20:18:29 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 1;
	hi = nb;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid <= nb / mid)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (0);
}
