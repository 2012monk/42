/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:55:16 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/22 21:55:16 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*dst;

	dst = (int *) malloc(sizeof(int) * length);
	if (!dst)
		return (dst);
	i = -1;
	while (++i < length)
		dst[i] = f(tab[i]);
	return (dst);
}
