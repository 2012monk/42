/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:03:17 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/18 15:03:18 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	f_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * f_abs(max - min));
	if (*range == NULL)
		return (-1);
	i = -1;
	while ((++i + min) < max)
		range[0][i] = i + min;
	return (f_abs(max - min));
}
