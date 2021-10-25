/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:13:27 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/24 02:13:28 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	f_memcpy(void *dst, void *src, unsigned int len)
{
	char			*to;
	char			*from;
	unsigned int	i;

	to = (char *) dst;
	from = (char *) src;
	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
}
