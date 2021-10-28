/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:02:57 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/27 16:02:58 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	f_memcpy(void *dst, void *src, unsigned int len)
{
	char			*to;
	char			*from;
	unsigned int	i;

	to = (char *) dst;
	from = (char *) src;
	if (!len)
		return ;
	i = -1;
	if (src < dst)
	{
		to = (char *) dst;
		from = (char *) src;
		while (++i < len)
			to[len - i - 1] = from[len - i - 1];
	}
	else
	{
		while (++i < len)
			((char *) dst)[i] = ((char *) src)[i];
	}
}

void	ft_strncpy(char *dst, char *src, unsigned int len)
{
	while (len--)
		*dst++ = *src++;
}

void	*ft_realloc(void *src, unsigned int old_size, unsigned int new_size)
{
	void	*pt;

	if (!src)
		return (malloc(sizeof(char) * new_size));
	(void) old_size;
	pt = malloc(sizeof(char) * (new_size));
	if (pt == NULL)
		return (NULL);
	f_memcpy(pt, src, old_size);
	free(src);
	return (pt);
}

void	*stdin_err(char *buf)
{
	if (buf)
		free(buf);
	return (NULL);
}

char	*parse_stdin(void)
{
	char			*buffer;
	char			*buf;
	int				size;
	int				total;

	buf = NULL;
	buffer = (char *) malloc(sizeof(char) * BUF_SIZE);
	total = 0;
	if (!buffer)
		return (NULL);
	size = read(0, buffer, BUF_SIZE);
	while (size > 0)
	{
		buf = ft_realloc(buf, total, sizeof(char) * (total + size + 1));
		if (!buf)
			return (NULL);
		f_memcpy(&buf[total], buffer, size);
		total += size;
		size = read(0, buffer, BUF_SIZE);
	}
	free(buffer);
	if (size < 0 || !total)
		return (stdin_err(buf));
	buf[total] = '\0';
	return (buf);
}
