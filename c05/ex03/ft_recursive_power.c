/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:05:59 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 20:06:00 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	ret;

	if (power < 0)
		return (0);
	if (!power)
		return (1);
	ret = ft_recursive_power(nb, power / 2);
	ret *= ret;
	if (power & 1)
		ret *= nb;
	return (ret);
}
