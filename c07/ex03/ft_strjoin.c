/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:01:55 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/18 16:01:56 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fstrcat(char *dst, char *src)
{
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
}

int	total_length(char **str, int size)
{
	int	i;
	int	total;

	i = -1;
	total = 0;
	while (++i < size)
		total += ft_strlen(str[i]);
	return (total);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*dst;
	int		i;
	int		total;

	if (size <= 0)
	{
		dst = (char *)malloc(sizeof(char));
		*dst = '\0';
		return (dst);
	}
	total = (size - 1) * ft_strlen(sep) + total_length(str, size);
	dst = (char *) malloc(sizeof(char) * (total + 1));
	if (!dst)
		return (NULL);
	i = -1;
	*dst = '\0';
	while (++i < size)
	{
		fstrcat(dst, str[i]);
		if (i < size - 1)
			fstrcat(dst, sep);
	}
	return (dst);
}
