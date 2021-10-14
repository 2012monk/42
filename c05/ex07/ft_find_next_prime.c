/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:33:02 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 20:39:59 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	lo;
	int	hi;
	int	mid;
	int	ret;

	lo = 1;
	hi = nb;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid <= nb / mid)
		{
			lo = mid + 1;
			ret = mid;
		}
		else
			hi = mid - 1;
	}
	return (ret);
}

int	is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 1;
	while (++i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}
