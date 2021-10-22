/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:44:19 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/20 22:44:27 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	fstrcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = *src;
}

char	*ft_strdup(char *src)
{
	char			*dst;
	unsigned int	size;

	size = ft_strlen(src) + 1;
	dst = (char *) malloc(size);
	if (!dst)
		return (0);
	fstrcpy(dst, src);
	return (dst);
}
