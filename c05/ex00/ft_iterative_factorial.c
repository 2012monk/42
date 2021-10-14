/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:43:43 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/13 19:43:44 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;
	int	i;

	if (nb < 0)
		return (0);
	ret = 1;
	i = 1;
	while (i <= nb)
		ret *= i++;
	return (ret);
}
